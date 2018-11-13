while (hp != NIL_HOLE && hp->h_base < swap_base) {
	if (hp->h_len >= clicks) {
		/* We found a hole that is big enough.  Use it. */
		old_base = hp->h_base;	/* remember where it started */
		hp->h_base += clicks;	/* bite a piece off */
		hp->h_len -= clicks;	/* ditto */

		/* Remember new high watermark of used memory. */
		if(hp->h_base > high_watermark)
			high_watermark = hp->h_base;

		/* Delete the hole if used up completely. */
		if (hp->h_len == 0) del_slot(prev_ptr, hp);

		/* Return the start address of the acquired block. */
		return(old_base);
	}

	prev_ptr = hp;
	hp = hp->h_next;
}