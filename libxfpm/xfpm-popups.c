/*
 * * Copyright (C) 2008-2009 Ali <aliov@xfce.org>
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <gtk/gtk.h>
#include <glib.h>

#include "xfpm-popups.h"

static GtkWidget *
xfpm_message_dialog (const gchar *title, const gchar *message, GtkMessageType message_type)
{
    GtkWidget *dialog;
    
    dialog = gtk_message_dialog_new_with_markup(NULL,
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                message_type,
                                                GTK_BUTTONS_CLOSE,
                                                "<span size='larger'><b>%s</b></span>",
                                                title);
                                                
    gtk_message_dialog_format_secondary_markup(GTK_MESSAGE_DIALOG(dialog), "%s", message);
    
    return dialog;
}

void xfpm_popup_message(const gchar *title,
                        const gchar *message,
                        GtkMessageType message_type)
{
    
    GtkWidget *dialog;
    
    dialog = xfpm_message_dialog (title, message, message_type);
    
    g_signal_connect(dialog,
                     "response",
                     G_CALLBACK(gtk_widget_destroy),
                     NULL);
                     
    gtk_widget_show(dialog);                         
}                 

void xfpm_info (const gchar *title, const gchar *message )
{
    GtkWidget *dialog;
    
    dialog = xfpm_message_dialog (title, message, GTK_MESSAGE_INFO);
    
    gtk_dialog_run (GTK_DIALOG(dialog));
    gtk_widget_destroy (dialog);
}

void    xfpm_error              (const gchar *title,
				 const gchar *message)
{
    GtkWidget *dialog;
    
    dialog = xfpm_message_dialog (title, message, GTK_MESSAGE_ERROR);
    
    gtk_dialog_run (GTK_DIALOG(dialog));
    gtk_widget_destroy (dialog);
}
