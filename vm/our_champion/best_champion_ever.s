# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    best_champion_ever.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 18:00:29 by yhetman           #+#    #+#              #
#    Updated: 2019/10/30 18:10:45 by yhetman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.name           "BEST CHAMPION EVER"
.comment        "just the best of the best"

start:	live	%700
	ld	%0,r5
	ld	%0,r5
	zjmp	%:attack

attack:	sti     r1,%:copier,%2
        ldi     %:copier,%3,r2
        sti     r2,%:start,%-4
        ldi     %:copier,%-1,r2
        sti     r2,%:copier,%-8
		sti	r1,%:copier,%1

copier:  ld      %1,r1

