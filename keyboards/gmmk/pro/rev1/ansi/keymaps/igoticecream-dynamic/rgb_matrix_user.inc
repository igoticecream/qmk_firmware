RGB_MATRIX_EFFECT(STATUS)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// https://github.com/qmk/qmk_firmware/issues/14686
// [Bug] Cannot control RGB Matrix manually, colors repeatedly overwritten with solid color under RGB_MATRIX_NONE mode #14686
// As a workaround, define a custom effect that does nothing, set it as the init default in keymap.c: rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_STATUS);
// When this effect is active, values written with rgb_matrix_set_color() aren't overwritten.

bool STATUS(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    HSV      hsv  = rgb_matrix_config.hsv;
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    hsv.v         = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    RGB rgb       = rgb_matrix_hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
