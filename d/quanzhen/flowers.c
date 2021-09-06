// Code of ShenZhou
// wsky, 5/7/00
inherit ROOM;

#include <ansi.h>

int do_hide();
int do_look();
int event_one(object me);
int event_two(object me);
int event_three(object me);

void create()
{
        set("short", "������");
        set("long", @LONG
����������ɽ��ɽ�Ļ����У���Ժ컨�ſ����������ɣ����ܲ�㣬����
�˱ǡ�������������һ������磬�����֦��ɷ�Ǻÿ������������񴹸�
��������Ȼ��ɵ�һ���������ݡ���Щ�컨(flowers)�ƺ������ƿ���
LONG);

	set("item_desc", ([
	        "flowers" : "�⻨�Լ������ܣ�����һ���ܺõĲ���֮����\n",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "quanzhen");

        set("cost", 2);
        setup();
        

}

void init()
{       
        add_action("do_hide", "hide");
        add_action("do_hide", "cang");
        add_action("do_push", "push");
        add_action("do_push", "tui");
}

int do_hide(){

	object me=this_player();
	if (me->is_busy())
		return notify_fail("��������æ���ģ�\n");

	if (me->query_temp("hiding"))
		return notify_fail("���Ѿ��غ��ˡ�\n");
	
        if (me->query_temp("found_lianhuan_book") || me->query("quest/quanzhen/sword/lianhuan"))
		return notify_fail("�㻹��ʲô��\n");
	
	tell_object(me, "��С������زص��˻����С�\n");
	
	me->set_temp("hiding",1);
	
	
	call_out("event_one", 10, me);
	
	return 1;
}

int do_push(){

	object room;
	object me=this_player();
	
	if (me->is_busy())
		return notify_fail("��������æ���ģ�\n");

	tell_object(me, "��������ƿ���ľ���������˳�ȥ��\n");
	
	me->set_temp("hiding",1);
	me->delete_temp("hiding");
	
        room = load_object("/d/quanzhen/milin");
	
	room->set("hide_person",1);
	room->delete("hide_person");
	
	me->move(room);
        return 1;

}

int event_one(object me){
	
	if(me->query_temp("hiding")){
	
		tell_object(me, HIG"ͻȻ��ɽ�����Ų����죬������һ��˵����һ���߽���ԭ��������־ƽ����־����������Խ˵Խ�����������ڻ������硣\n"NOR);
		
		remove_call_out("event_one");
		call_out("event_two", 5, me);
	}

	return 1;
}

int event_two(object me){
	
	if(me->query_temp("hiding")){
	
		tell_object(me, HIG"ֻ������־����Ц�������㲻����棬�����ҽ̵Ĵ�䣬���������������ӣ������������ƣ���֪��־��ʲô��˼��\n"NOR);
		tell_object(me, HIG"�������ֹ��У�����������Խ��Խ�ס�ͻȻ�䣬��־�����������㻹�ҵ�������������ʦ������ȥ��\n"NOR);
		tell_object(me, HIG"��־ƽ��Ҳ���Ͳ�ס��৵�һ�����������ʣ����ı�̣���־������ܿ����齣��ϻ�����˴�һ��\n"NOR);
		
		remove_call_out("event_one");
		call_out("event_three", 15, me);
	}
	
	return 1;
}


int event_three(object me){
	
	if(me->query_temp("hiding")){
	
		tell_object(me, HIG"ֻ�����Զ��˳���������ã��ѷ�����֪���㲻��������ȫ���亹��\n"NOR);
		tell_object(me, HIR"\n\n�ٲ����У���־ƽ��ƽ�̣�����������ͬʱ���Ⱥ�ɨ����������ȫ�����еġ������������С�\n"NOR);
				
		remove_call_out("event_two");
		call_out("event_four", 15, me);
	}
	
	return 1;
}

int event_four(object me){
	
	object book;
	
	if(me->query_temp("hiding")){
	
		tell_object(me, HIG"ֻ����־ƽ����ŭ�ȣ��������У���Ȼ���ٵ��ݶԷ����У�һζ�͹���\n"NOR);
		tell_object(me, HIG"\n\n�ٲ����У���־���ڶԷ�ƴ���½����мܲ�ס�����������ȥ��\n"NOR);
		
		tell_object(me, HIY"\n\n��־ƽһ㶣����׷ȥ����ֻ����વ�һ����һ��С���Ӵ���־ƽ���ϵ���������\n"NOR);
		tell_object(me, "\n\n����־ƽ�ߺ���æ������С���Ӽ���������\n"NOR);
		
		me->set_temp("found_lianhuan_book", 1);
		me->delete_temp("hiding", 1);
		book=new("/d/quanzhen/obj/lh_book");
		book->set("player_id", me->query("id"));
		book->move(me);
						
		remove_call_out("event_three");
		
	}
	
	return 1;
}
