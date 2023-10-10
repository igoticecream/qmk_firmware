RGB_MATRIX_EFFECT(STATUS)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// https://github.com/qmk/qmk_firmware/issues/14686
// [Bug] Cannot control RGB Matrix manually, colors repeatedly overwritten with solid color under RGB_MATRIX_NONE mode #14686
// As a workaround, define a custom effect that does nothing, set it as the init default in keymap.c: rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_STATUS);
// When this effect is active, values written with rgb_matrix_set_color() aren't overwritten.

bool STATUS(effect_params_t* params) {
    // rgb_matrix_set_color_all(RGB_OFF);
    return false;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
