/*
* libtcod 1.6.3
* Copyright (c) 2008,2009,2010,2012,2013,2016,2017 Jice & Mingos & rmtew
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * The name of Jice or Mingos may not be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY JICE, MINGOS AND RMTEW ``AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL JICE, MINGOS OR RMTEW BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _TCOD_CONSOLE_H
#define _TCOD_CONSOLE_H

#include "libtcod_portability.h"

#ifdef TCOD_CONSOLE_SUPPORT

#include "color.h"
#include "console_types.h"
#include "image.h"
#include "list.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TCOD_BKGND_ALPHA(alpha) ((TCOD_bkgnd_flag_t)(TCOD_BKGND_ALPH|(((uint8_t)(alpha*255))<<8)))
#define TCOD_BKGND_ADDALPHA(alpha) ((TCOD_bkgnd_flag_t)(TCOD_BKGND_ADDA|(((uint8_t)(alpha*255))<<8)))

TCODLIB_API void TCOD_console_init_root(int w, int h, const char * title, bool fullscreen, TCOD_renderer_t renderer);
TCODLIB_API void TCOD_console_set_window_title(const char *title);
TCODLIB_API void TCOD_console_set_fullscreen(bool fullscreen);
TCODLIB_API bool TCOD_console_is_fullscreen(void);
TCODLIB_API bool TCOD_console_is_window_closed(void);
TCODLIB_API bool TCOD_console_has_mouse_focus(void);
TCODLIB_API bool TCOD_console_is_active(void);

TCODLIB_API void TCOD_console_set_custom_font(const char *fontFile, int flags,int nb_char_horiz, int nb_char_vertic);
TCODLIB_API void TCOD_console_map_ascii_code_to_font(int asciiCode, int fontCharX, int fontCharY);
TCODLIB_API void TCOD_console_map_ascii_codes_to_font(int asciiCode, int nbCodes, int fontCharX, int fontCharY);
TCODLIB_API void TCOD_console_map_string_to_font(const char *s, int fontCharX, int fontCharY);

TCODLIB_API void TCOD_console_set_dirty(int x, int y, int w, int h);
TCODLIB_API void TCOD_console_set_default_background(TCOD_console_t con,TCOD_color_t col);
TCODLIB_API void TCOD_console_set_default_foreground(TCOD_console_t con,TCOD_color_t col);
TCODLIB_API void TCOD_console_clear(TCOD_console_t con);
TCODLIB_API void TCOD_console_set_char_background(TCOD_console_t con,int x, int y, TCOD_color_t col, TCOD_bkgnd_flag_t flag);
TCODLIB_API void TCOD_console_set_char_foreground(TCOD_console_t con,int x, int y, TCOD_color_t col);
TCODLIB_API void TCOD_console_set_char(TCOD_console_t con,int x, int y, int c);
TCODLIB_API void TCOD_console_put_char(TCOD_console_t con,int x, int y, int c, TCOD_bkgnd_flag_t flag);
TCODLIB_API void TCOD_console_put_char_ex(TCOD_console_t con,int x, int y, int c, TCOD_color_t fore, TCOD_color_t back);

TCODLIB_API void TCOD_console_set_background_flag(TCOD_console_t con,TCOD_bkgnd_flag_t flag);
TCODLIB_API TCOD_bkgnd_flag_t TCOD_console_get_background_flag(TCOD_console_t con);
TCODLIB_API void TCOD_console_set_alignment(TCOD_console_t con,TCOD_alignment_t alignment);
TCODLIB_API TCOD_alignment_t TCOD_console_get_alignment(TCOD_console_t con);
TCODLIB_API void TCOD_console_print(TCOD_console_t con,int x, int y, const char *fmt, ...);
TCODLIB_API void TCOD_console_print_ex(TCOD_console_t con,int x, int y, TCOD_bkgnd_flag_t flag, TCOD_alignment_t alignment, const char *fmt, ...);
TCODLIB_API int TCOD_console_print_rect(TCOD_console_t con,int x, int y, int w, int h, const char *fmt, ...);
TCODLIB_API int TCOD_console_print_rect_ex(TCOD_console_t con,int x, int y, int w, int h, TCOD_bkgnd_flag_t flag, TCOD_alignment_t alignment, const char *fmt, ...);
TCODLIB_API int TCOD_console_get_height_rect(TCOD_console_t con,int x, int y, int w, int h, const char *fmt, ...);

TCODLIB_API void TCOD_console_rect(TCOD_console_t con,int x, int y, int w, int h, bool clear, TCOD_bkgnd_flag_t flag);
TCODLIB_API void TCOD_console_hline(TCOD_console_t con,int x,int y, int l, TCOD_bkgnd_flag_t flag);
TCODLIB_API void TCOD_console_vline(TCOD_console_t con,int x,int y, int l, TCOD_bkgnd_flag_t flag);
TCODLIB_API void TCOD_console_print_frame(TCOD_console_t con,int x,int y,int w,int h, bool empty, TCOD_bkgnd_flag_t flag, const char *fmt, ...);

#ifndef NO_UNICODE
/* unicode support */
TCODLIB_API void TCOD_console_map_string_to_font_utf(const wchar_t *s, int fontCharX, int fontCharY);
TCODLIB_API void TCOD_console_print_utf(TCOD_console_t con,int x, int y, const wchar_t *fmt, ...);
TCODLIB_API void TCOD_console_print_ex_utf(TCOD_console_t con,int x, int y, TCOD_bkgnd_flag_t flag, TCOD_alignment_t alignment, const wchar_t *fmt, ...);
TCODLIB_API int TCOD_console_print_rect_utf(TCOD_console_t con,int x, int y, int w, int h, const wchar_t *fmt, ...);
TCODLIB_API int TCOD_console_print_rect_ex_utf(TCOD_console_t con,int x, int y, int w, int h, TCOD_bkgnd_flag_t flag, TCOD_alignment_t alignment, const wchar_t *fmt, ...);
TCODLIB_API int TCOD_console_get_height_rect_utf(TCOD_console_t con,int x, int y, int w, int h, const wchar_t *fmt, ...);
#endif


TCODLIB_API TCOD_color_t TCOD_console_get_default_background(TCOD_console_t con);
TCODLIB_API TCOD_color_t TCOD_console_get_default_foreground(TCOD_console_t con);
TCODLIB_API TCOD_color_t TCOD_console_get_char_background(TCOD_console_t con,int x, int y);
TCODLIB_API TCOD_color_t TCOD_console_get_char_foreground(TCOD_console_t con,int x, int y);
TCODLIB_API int TCOD_console_get_char(TCOD_console_t con,int x, int y);

TCODLIB_API TCOD_image_t TCOD_console_get_background_color_image(TCOD_console_t con);
TCODLIB_API TCOD_image_t TCOD_console_get_foreground_color_image(TCOD_console_t con);

TCODLIB_API void TCOD_console_set_fade(uint8_t val, TCOD_color_t fade);
TCODLIB_API uint8_t TCOD_console_get_fade(void);
TCODLIB_API TCOD_color_t TCOD_console_get_fading_color(void);

TCODLIB_API void TCOD_console_flush(void);

TCODLIB_API void TCOD_console_set_color_control(TCOD_colctrl_t con, TCOD_color_t fore, TCOD_color_t back);

TCODLIB_API TCOD_key_t TCOD_console_check_for_keypress(int flags);
TCODLIB_API TCOD_key_t TCOD_console_wait_for_keypress(bool flush);
TCODLIB_API bool TCOD_console_is_key_pressed(TCOD_keycode_t key);

/* ASCII paint file support */
TCODLIB_API TCOD_console_t TCOD_console_from_file(const char *filename);
TCODLIB_API bool TCOD_console_load_asc(TCOD_console_t con, const char *filename);
TCODLIB_API bool TCOD_console_load_apf(TCOD_console_t con, const char *filename);
TCODLIB_API bool TCOD_console_save_asc(TCOD_console_t con, const char *filename);
TCODLIB_API bool TCOD_console_save_apf(TCOD_console_t con, const char *filename);

TCODLIB_API TCOD_console_t TCOD_console_new(int w, int h);
TCODLIB_API int TCOD_console_get_width(TCOD_console_t con);
TCODLIB_API int TCOD_console_get_height(TCOD_console_t con);
TCODLIB_API void TCOD_console_set_key_color(TCOD_console_t con,TCOD_color_t col);
TCODLIB_API void TCOD_console_blit(TCOD_console_t src,int xSrc, int ySrc, int wSrc, int hSrc, TCOD_console_t dst, int xDst, int yDst, float foreground_alpha, float background_alpha);
TCODLIB_API void TCOD_console_delete(TCOD_console_t console);

TCODLIB_API void TCOD_console_credits(void);
TCODLIB_API void TCOD_console_credits_reset(void);
TCODLIB_API bool TCOD_console_credits_render(int x, int y, bool alpha);

/* REXPaint support */
TCODLIB_API TCOD_console_t TCOD_console_from_xp(const char *filename);
TCODLIB_API bool TCOD_console_load_xp(TCOD_console_t con, const char *filename);
TCODLIB_API bool TCOD_console_save_xp(TCOD_console_t con, const char *filename, int compress_level);
TCODLIB_API TCOD_list_t TCOD_console_list_from_xp(const char *filename);
TCODLIB_API bool TCOD_console_list_save_xp(TCOD_list_t console_list, const char *filename, int compress_level);
#ifdef __cplusplus
}
#endif

#endif /* TCOD_CONSOLE_SUPPORT */

#endif /* _TCOD_CONSOLE_H */
