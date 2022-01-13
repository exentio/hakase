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
#define UART_MSGLEN 4

typedef enum {
    TD_NONE,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_RELEASE
} td_state_t;

enum dance_kcodes {
    UKC_0,
    UKC_1,
    UKC_2,
    UKC_3,
    UKC_4,
    UKC_5,
    UKC_6,
    UKC_7
};

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;