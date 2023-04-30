#include "routes.h"

#include <stdlib.h>

#include <string.h>

#include <stdio.h>

// Map implementation using BST

struct Route * initRoute(char * key, char * value) {
    struct Route * temp = (struct Route * ) malloc(sizeof(struct Route));

    temp -> key = key;
    temp -> value = value;

    temp -> left = temp -> right = NULL;
    return temp;
}

void displayRoutes(struct Route * root) {

    if (root != NULL) {
        displayRoutes(root -> left);
        printf("%s -> %s \n", root -> key, root -> value);
        displayRoutes(root -> right);
    }
}

struct Route * addRoute(struct Route * root, char * key, char * value) {
    if (root == NULL) {
        return initRoute(key, value);
    }

    if (strcmp(key, root -> key) == 0) {
        printf("warning: a route for \"%s\" already exists\n", key);
        return root;
    }

    if (strcmp(key, root -> key) > 0) {
        if (root -> right == NULL) {
            root -> right = initRoute(key, value);
        } else {
            root -> right = addRoute(root -> right, key, value);
        }
    } else {
        if (root -> left == NULL) {
            root -> left = initRoute(key, value);
        } else {
            root -> left = addRoute(root -> left, key, value);
        }
    }

    return root;
}

struct Route * search(struct Route * root, char * key) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(key, root -> key) == 0) {
        return root;
    } else if (strcmp(key, root -> key) > 0) {
        return search(root -> right, key);
    } else if (strcmp(key, root -> key) < 0) {
        return search(root -> left, key);
    }
    return NULL;
}