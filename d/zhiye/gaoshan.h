// gaoshan.h
// augx@sj 2/27/2002

void init()
{
	add_action("do_search","sousuo");
	add_action("do_search","search");
	add_action("do_caiyao","caiyao");
}

int do_search(string arg)
{
	object me = this_player();
	int i,j,x,y;

	if ( me->is_busy() ) return notify_fail("ÄãÕýÃ¦×ÅÄØ£¡\n");

	i = random(8)+1;
	if(i>4) i++;
	me->set_temp("worker/caiyao_go",i);
	me->set_temp("worker/caiyao_count",query("yaocai"));

	tell_object(me, CYN"ÄãËÄ´¦ËÑË÷Ò©²ÄµÄºÛ¼£......\n"NOR);
	tell_object(me, HIC"================================\n");
	for(j=0;j<15;j++)
		tell_object(me,"|[30C|\n");
	tell_object(me, "================================\n"NOR);
	
	switch(i) {
		case 1: x =  2; y = 12; break;
		case 2: x =  7; y = 12; break;
		case 3: x = 12; y = 12; break;
		case 4: x =  2; y =  7; break;
		case 6: x = 12; y =  7; break;
		case 7: x =  2; y =  2; break;
		case 8: x =  7; y =  2; break;
		case 9: x = 12; y =  2; break;
	}
	tell_object(me,sprintf(HIY"[%dA[%dC**[%dB\n"NOR,16-y,x*2+1,15-y));
	
	if(!wizardp(me)) me->start_busy(3);
	return 1;
}

int gowrong(object me)
{
	object room;
	if( random(10)!=3 )
		return notify_fail("ÄÇ¸ö·½ÏòÃ»ÓÐÒ©²Ä°¡£¡\n");
	else {
		message_vision("\n$NÒ»Â·Ñ°ÕÒÒ©²Ä£¬²»Öª²»¾õ×ßµ½ÐüÑÂ±ß£¬Ò»²»ÁôÉñ¾ÍË¤ÁËÏÂÈ¥......\n\n",me);
		room = find_object(__DIR__"gaoshan0");
		if(room) me->move(room);
		message_vision(RED"\n$NÒ»¸ö²»ÁôÉñ´Ó´ÓÉ½ÉÏµôÁËÏÂÀ´£¬Ë¤µÄ·ÛÉíËé¹Ç£¡\n"NOR,me);
		me->set_temp("last_damage_from","µøÏÂÐüÑÂ");
		me->die();
		return 1;
	}
}

int do_caiyao(string arg)
{
	object me = this_player() , weapon;
	string dir,yaocai;
	int level,delay;
	
	if ( !arg || sscanf(arg,"%s at %s",yaocai,dir)<2 ) return notify_fail("ÄãÒªÍÚÊ²Ã´£¿\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="yao chu" || weapon->query("worker")!=1 )
		return notify_fail("Äã±ØÐë×°±¸Ò©³ú²ÅÄÜ²ÉÒ©¡£\n");
	if ( me->is_busy() )
		return notify_fail("ÄãÕýÃ¦×ÅÄØ£¡\n");	
	if ( !wizardp(me) && (time()<(int)me->query("worker/caiyao")) )
		return notify_fail("Äã¸Õ¸Õ²ÉÒ©½áÊø£¬¸Ð¾õ¹ýÓÚÀÍÀÛ£¡\n");	
	level = (int)me->query_skill("caiyao",1);
	if ( level<1 )
		return notify_fail("Äã¸ù±¾¾Í²»»á²ÉÒ©£¡\n");
	
	switch( me->query_temp("worker/caiyao_go") ) {
		case 1: if(dir!="southwest")	return gowrong(me); dir="Î÷ÄÏ"; break;
		case 2: if(dir!="south")	return gowrong(me); dir="ÄÏ";   break;
		case 3: if(dir!="southeast")	return gowrong(me); dir="¶«ÄÏ"; break;
		case 4: if(dir!="west")		return gowrong(me); dir="Î÷";   break;
		case 6: if(dir!="east")		return gowrong(me); dir="¶«";   break;
		case 7: if(dir!="northwest")	return gowrong(me); dir="Î÷±±"; break;
		case 8: if(dir!="north")	return gowrong(me); dir="±±";   break;
		case 9: if(dir!="northeast")	return gowrong(me); dir="¶«±±"; break;
		default: return notify_fail("ÄãÒªÍùÄÄ¸ö·½ÏòÈ¥ËÑË÷Ò©²Ä£¿\n"); break;
	}

	if( me->query_temp("worker/caiyao_count") <= 0 )
		return notify_fail("ÄãÒÑ¾­°ÑÕâ¸ö·½ÏòÄã¿ÉÒÔ·¢ÏÖµÄÒ©²Ä¶¼²É×ßÁË£¡\n");
		
	message_vision(HIY"$N²»Í£µÄÍù"+dir+"·½ËÑË÷£¬Ï£ÍûÄÜÕÒµ½Ò»Ð©Ò©²Ä......\n\n"NOR, me);
	delay = 8 + random(15);
	if(wizardp(me) && (int)me->query("env/test")) delay = 2;
	me->start_busy(delay+1);
	call_out("caiyao_finish",delay*2-1,me,yaocai);
	return 1;
}

void caiyao_finish(object me,string yaocai)
{			
	object tools,obj;
	int level,i=1,improve;
	
	if(!objectp(me) || !userp(me)) return;	
	me->start_busy(-1);
	me->interrupt_me();
	tools = me->query_temp("weapon");
	level = (int)me->query_skill("caiyao",1);
	if ( objectp(tools) && tools->query("id")=="yao chu" )
		tools->use();
		
	obj = new(__DIR__"obj/yaocai");
	if(!obj) return;
	if( obj->set_type(yaocai) != 1 ) {
		message_vision(YEL"$NÑ°ÕÒÁËºÃ³¤Ò»¶ÎÊ±¼ä£¬¸ü±¾²»ÖªµÀÔÚÕÒÊ²Ã´¶«Î÷......\n"NOR, me);
		destruct(obj);
		return;
	}
	obj->set_level(level);	
	if( level < obj->query("need_lvl") ) {
		message_vision(YEL"$NÑ°ÕÒÁËºÃ³¤Ò»¶ÎÊ±¼ä£¬×îºó·¢ÏÖ×Ô¼ºÄÜÁ¦²»×ã£¬¸ü±¾ÕÒ²»µ½ÕâÖÖÒ©²Ä£¡\n"NOR, me);
		destruct(obj);
		return;
	}
	
	if(level>390) level = 390 + (level-390)*11;
	i = obj->query("need_lvl");
	if(i<80)       i = 80;
	else if(i<160) i = 160;
	else if(i<240) i = 240;
	else if(i<320) i = 320;
	else if(i<360) i = 360;
	else if(i<390) i = 390;
	else           i = 500;
	if ( i>(level*2) ) i=level*2;
	improve = me->query_int(1) * i/level;
	
	i = obj->query("need_lvl");
	if(i<80)       { i = 80;  if(level>150) level=150; }
	else if(i<160) { i = 160; if(level>250) level=250; }
	else if(i<240) { i = 280; if(level>350) level=350; }
	else if(i<320) { i = 360; if(level>450) level=450; }
	else if(i<360) { i = 400; if(level>500) level=500; }
	else if(i<390) { i = 500; if(level>500) level=500; }
	else           { i = 700; if(level>500) level=500; }
	
	if( random(level+i) > i ) {
		me->improve_skill("caiyao", improve*7);
		me->add("combat_exp", random(improve/2));
		me->add("potential", random(improve/7*2));		
		
		message_vision(YEL"$NÑ°ÕÒÁËºÃ³¤Ò»¶ÎÊ±¼ä£¬×ÜËãÕÒµ½Ò»Ð©"+obj->query("name")+"¡£\n"NOR, me);
		me->add_temp("worker/caiyao_count",-1);
		
		if( !obj->move(me) ) destruct(obj);
		for(i=0;i<2;i++) {
			obj = new(__DIR__"obj/yaocai");
			obj->set_type(yaocai);
			obj->set_level(me->query_skill("caiyao",1));
			if( !obj->move(me) ) destruct(obj);
		}
	}
	else {
		me->improve_skill("caiyao", improve*2);
		me->add("combat_exp", random(improve/3));
		me->add("potential", random(improve/7));
		destruct(obj);
		message_vision(HIY"$NÑ°ÕÒÁËºÃ³¤Ò»¶ÎÊ±¼ä£¬µ«ÊÇÊ²Ã´¶¼Ã»ÓÐµÃµ½¡£\n"NOR, me);
	}
	
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	me->set("worker/caiyao",time()+5+random(6));
}
