/* Copyright 2022 Exentio Kawasaki
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "uart.h"
#include "uart_tap_dance.h"

uint8_t msg[UART_MSGLEN];

static td_tap_t tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

td_state_t curr_dance(tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
            else return TD_SINGLE_HOLD;
        case 2:
            if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
            else return TD_DOUBLE_HOLD;
        default:
            return TD_NONE;
    }
}

uint8_t* uart_data_code(uint16_t keycode, int press_type) {
    msg[0] = '0' + (keycode / 10);
    msg[1] = '0' + (keycode % 10);
    msg[3] = '\n';
    switch(press_type) {
        case TD_SINGLE_TAP:
            msg[2] = 'T';
            break;
        case TD_SINGLE_HOLD:
            msg[2] = 'H';
            break;
        case TD_DOUBLE_TAP:
            msg[2] = 'D';
            break;
        case TD_DOUBLE_HOLD:
            msg[2] = 'B';
            break;
        case TD_RELEASE:
            msg[2] = 'R';
            break;
        case TD_NONE:
        default:
            msg[2] = 'X';
            break;
    }
    return msg;
}

void dance_reg_switching(int curr_uart_kc) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            uart_transmit(uart_data_code(curr_uart_kc, TD_SINGLE_TAP), UART_MSGLEN);
            break;
        case TD_SINGLE_HOLD:
            uart_transmit(uart_data_code(curr_uart_kc, TD_SINGLE_HOLD), UART_MSGLEN);
            break;
        case TD_DOUBLE_TAP:
            uart_transmit(uart_data_code(curr_uart_kc, TD_DOUBLE_TAP), UART_MSGLEN);
            break;
        case TD_DOUBLE_HOLD:
            uart_transmit(uart_data_code(curr_uart_kc, TD_DOUBLE_HOLD), UART_MSGLEN);
            break;
        default:
            uart_transmit(uart_data_code(curr_uart_kc, TD_NONE), UART_MSGLEN);
            break;
    }
}

void dance_release(int curr_uart_kc) {
    if (tap_state.state != TD_NONE)
        uart_transmit(uart_data_code(curr_uart_kc, TD_RELEASE), UART_MSGLEN);
}

void ukc0_press(tap_dance_state_t *state, void *user_data) {
    tap_state.state = curr_dance(state);
    dance_reg_switching(UKC_0);
}

void ukc1_press(tap_dance_state_t *state, void *user_data) {
    tap_state.state = curr_dance(state);
    dance_reg_switching(UKC_1);
}

void ukc2_press(tap_dance_state_t *state, void *user_data) {
    tap_state.state = curr_dance(state);
    dance_reg_switching(UKC_2);
}

void ukc3_press(tap_dance_state_t *state, void *user_data) {
    tap_state.state = curr_dance(state);
    dance_reg_switching(UKC_3);
}

void ukc4_press(tap_dance_state_t *state, void *user_data) {
    tap_state.state = curr_dance(state);
    dance_reg_switching(UKC_4);
}

void ukc5_press(tap_dance_state_t *state, void *user_data) {
    tap_state.state = curr_dance(state);
    dance_reg_switching(UKC_5);
}

void ukc6_press(tap_dance_state_t *state, void *user_data) {
    tap_state.state = curr_dance(state);
    dance_reg_switching(UKC_6);
}

void ukc7_press(tap_dance_state_t *state, void *user_data) {
    tap_state.state = curr_dance(state);
    dance_reg_switching(UKC_7);
}

void ukc0_release(tap_dance_state_t *state, void *user_data) {
    dance_release(UKC_0);
}

void ukc1_release(tap_dance_state_t *state, void *user_data) {
    dance_release(UKC_1);
}

void ukc2_release(tap_dance_state_t *state, void *user_data) {
    dance_release(UKC_2);
}

void ukc3_release(tap_dance_state_t *state, void *user_data) {
    dance_release(UKC_3);
}

void ukc4_release(tap_dance_state_t *state, void *user_data) {
    dance_release(UKC_4);
}

void ukc5_release(tap_dance_state_t *state, void *user_data) {
    dance_release(UKC_5);
}

void ukc6_release(tap_dance_state_t *state, void *user_data) {
    dance_release(UKC_6);
}

void ukc7_release(tap_dance_state_t *state, void *user_data) {
    dance_release(UKC_7);
}

tap_dance_action_t tap_dance_actions[] = {
    [UKC_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ukc0_press, ukc0_release),
    [UKC_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ukc1_press, ukc1_release),
    [UKC_2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ukc2_press, ukc2_release),
    [UKC_3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ukc3_press, ukc3_release),
    [UKC_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ukc4_press, ukc4_release),
    [UKC_5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ukc5_press, ukc5_release),
    [UKC_6] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ukc6_press, ukc6_release),
    [UKC_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ukc7_press, ukc7_release)
};
