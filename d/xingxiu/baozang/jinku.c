//tangfeng@SJ 8/2004

#include <ansi.h>
#include <room.h>
inherit ROOM;
#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"

void create()
{
        set("short",YEL"���"NOR);
        set("long", @long
�����ǽ�⣬����Կ���ż��ʧ��ı���ƽ�ֻ�Ǵ�˵�е���������
���أ��ƺ���û�з��֡�����������һЩ�򶷵ĺۼ�������������������
long);
        set("exits", ([
                "north" : __DIR__"tiantan",
                "south" : __DIR__"midong2",
                "east" : __DIR__"midong2",
                "west" : __DIR__"midong2",
        ]));
        set("quest", 1);
        set("baozang",1);
        setup();
}
void init()
{
  object me;
  if (interactive(me = this_player()) && me->query(QUESTDIR5+"start") && me->query_temp(QUESTDIR5+"search_ok") && !me->query(QUESTDIR5+"jinku"))
  {
       remove_call_out("greeting");
       call_out("greeting", 3, me);
	   me->start_busy(3);
  }       
}
void greeting(object me)
{
	object obj;
	if(!me) return;
	if(!present(me,this_object())) return;
	if(me->query(QUESTDIR5+"jinku")) return;

	me->set(QUESTDIR5+"jinku",1);  //
	obj=new("/clone/money/gold");
	obj->set_amount(300+random(300));
	obj->move(me);
    
	message_vision(WHT"\n$N����һЩ"+obj->query("name")+WHT"��\n"NOR, me);
	obj=new("/d/xingxiu/obj/yuqi");
	obj->move(me);
	message_vision(WHT"$N����һ��"+obj->query("name")+WHT"��\n"NOR, me);
	obj=new("/d/hj/obj/tu");
	obj->move(me);
	message_vision(WHT"$N����һ��"+obj->query("name")+WHT"��\n"NOR, me);
	obj=new("/d/hj/obj/tu");
	obj->move(me);
	message_vision(WHT"$N����һ��"+obj->query("name")+WHT"��\n"NOR, me);
	obj=new("/d/hj/obj/tu");
	obj->move(me);
	message_vision(WHT"$N����һ��"+obj->query("name")+WHT"��\n"NOR, me);
	obj=new("/d/hj/obj/shiqi");
	obj->move(me);
	message_vision(WHT"$N����һ��"+obj->query("name")+WHT"��\n"NOR, me);
	obj=new("/d/hj/obj/shiqi");
	obj->move(me);
	message_vision(WHT"$N����һ��"+obj->query("name")+WHT"��\n"NOR, me);
	obj=new("/d/hj/obj/shiqi");
	obj->move(me);
	message_vision(WHT"$N����һ��"+obj->query("name")+WHT"��\n"NOR, me);

	tell_object(me,HIR"\n���Ĵ�ת��һȦ����Ȼ�ҵ��ܶ������ƽ𣬻���һЩֵǮ��������������β�����а���\n"NOR);
	tell_object(me,HIG"ͻȻ���ֵ���һ�������۵�ʯ�塣�����ּ�����������Ȼ�Ǹ߲������\n"NOR);
	message("channel:rumor", HIM"��ҥ�ԡ���˵�ڴ������ص�"+environment(me)->query("short")+HIM"������ҵ���������ƽ�\n"NOR,users() );
	log_file("quest/FEIHU", sprintf("%s(%s)�ӱ����л�������Ļƽ�����������������%d��", me->name(1),me->query("id"), me->query("combat_exp")) );
}
