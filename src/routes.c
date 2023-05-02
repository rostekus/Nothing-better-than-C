#include "routes.h"

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

// Map implementation using BST

struct Route *initRoute(char *key, char *method, char *filename) {
  struct Route *temp = (struct Route *)malloc(sizeof(struct Route));

  temp->key = key;
  temp->method = method;
  temp->filename = filename;
  temp->left = temp->right = NULL;
  return temp;
}

void displayRoutes(struct Route *root) {
  if (root != NULL) {
    displayRoutes(root->left);
    printf("%s -> %s \n", root->key, root->method);
    displayRoutes(root->right);
  }
}

struct Route *addRoute(struct Route *root, char *key, char *method,
                       char *filename) {
  if (root == NULL) {
    return initRoute(key, method, filename);
  }

  if (strcmp(key, root->key) == 0) {
    printf("warning: a route for \"%s\" already exists\n", key);
    return root;
  }

  if (strcmp(key, root->key) > 0) {
    if (root->right == NULL) {
      root->right = initRoute(key, method, filename);
    } else {
      root->right = addRoute(root->right, key, method, filename);
    }
  } else {
    if (root->left == NULL) {
      root->left = initRoute(key, method, filename);
    } else {
      root->left = addRoute(root->left, key, method, filename);
    }
  }

  return root;
}

struct Route *search(struct Route *root, char *key) {
  if (root == NULL) {
    return NULL;
  }

  if (strcmp(key, root->key) == 0) {
    return root;
  } else if (strcmp(key, root->key) > 0) {
    return search(root->right, key);
  } else if (strcmp(key, root->key) < 0) {
    return search(root->left, key);
  }
  return NULL;
}

char *handleRequest(struct Route *root, Request *request) {
  char *template = (char *)malloc(100 * sizeof(char));
  memset(template, 0, 100);
  strcat(template, "");
  if (strstr(request->uri, "/static/") != NULL) {
    strcat(template, "static/index.css");

  } else {
    struct Route *destination = search(root, request->uri);
    strcat(template, "templates/");

    if (destination == NULL) {
      strcat(template, "404.html");
    }
    else if (strcmp(destination->method, request->method) != 0) {
      strcat(template, "404.html");
    } else {
      strcat(template, destination->filename);
    }
  }
  return template;
}