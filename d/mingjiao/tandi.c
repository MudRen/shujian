// tandi.c ̶��
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIB"̶��"NOR);
       set("long", @LONG
������ˮ��̶��̶�ף���Ȼ��һ�ɺ���ֱ�˶������㲻�ɵ�������һ��
���������Ͽ��������Ƕ���ֻ͸��˿˿���⣬ż�����������������������̶
��ȷʵ̫�䣬�������ܾ�����
LONG);    
	set("exits", ([
            "up" : __DIR__"bishui",				
	]));             	
        setup();
}

void run(object ob)
{
        if (!ob) return;
        if (environment(ob) == this_object()){
	remove_call_out("run");
	call_out("run", 10, ob);
	ob->set_temp("last_damage_from", "����̶����");
	ob->receive_damage("jing", 20);
	ob->receive_damage("qi", 20);
	write(HIB"\n��ֻ��һ���ݹǵĺ���ֱ����ͷ��\n\n"NOR);
	}
	return 0;
	
}

void init()
{
        object ob = this_player();
        call_out("run", 10+random(10), ob);
}
