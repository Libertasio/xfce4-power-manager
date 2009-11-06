/*
 * * Copyright (C) 2009 Ali <aliov@xfce.org>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef __XFPM_BRIGHTNESS_H
#define __XFPM_BRIGHTNESS_H

#include <glib-object.h>

G_BEGIN_DECLS

#define XFPM_TYPE_BRIGHTNESS        (xfpm_brightness_get_type () )
#define XFPM_BRIGHTNESS(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), XFPM_TYPE_BRIGHTNESS, XfpmBrightness))
#define XFPM_IS_BRIGHTNESS(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), XFPM_TYPE_BRIGHTNESS))

typedef enum
{
    XFPM_BRIGHTNESS_CONTROL_UNKNOWN,
    XFPM_BRIGHTNESS_CONTROL_XRANDR,
    XFPM_BRIGHTNESS_CONTROL_HAL
    
} XfpmBrightnessControl;

typedef struct XfpmBrightnessPrivate XfpmBrightnessPrivate;

typedef struct
{
    GObject         		parent;
    XfpmBrightnessPrivate      *priv;
    
} XfpmBrightness;

typedef struct
{
    GObjectClass 		parent_class;
    
} XfpmBrightnessClass;

GType        			xfpm_brightness_get_type        (void) G_GNUC_CONST;

XfpmBrightness       	       *xfpm_brightness_new             (void);

gboolean			xfpm_brightness_setup 		(XfpmBrightness *brightness);

gboolean			xfpm_brightness_up		(XfpmBrightness *brightness,
								 guint *new_level);

gboolean			xfpm_brightness_down		(XfpmBrightness *brightness,
								 guint *new_level);

gboolean			xfpm_brightness_has_hw 		(XfpmBrightness *brightness);

guint 				xfpm_brightness_get_max_level   (XfpmBrightness *brightness);

gboolean			xfpm_brightness_get_level	(XfpmBrightness *brightness,
								 guint *level);

gboolean			xfpm_brightness_set_level	(XfpmBrightness *brightness,
								 guint level);

gboolean			xfpm_brightness_dim_down	(XfpmBrightness *brightness);

XfpmBrightnessControl		xfpm_brightness_get_control	(XfpmBrightness *brightness);

gboolean			xfpm_brightness_in_hw		(XfpmBrightness *brightness);

G_END_DECLS

#endif /* __XFPM_BRIGHTNESS_H */
