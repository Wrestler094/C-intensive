#include "documentation_module.h"

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    for (int *ptr = &document_count; document_count > 0; document_count--) {
        validate(*(++ptr));
    }
}

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);

    return validation_result;
}
