// Room: /d/city/laofang.c
// Build by Looklove@sj 2000/10/16
// 2001.9.29 update

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�η�");
	set("long", @LONG
�������η���������ܳ�ʪ�����߻谵������������һ�ɳ��������˻���
��������������ڽ��ϵ����㱼���������ڽ����������š�͸��������ص���
�ţ�ż������һ�����ߺ�������������������ʲô���ˡ�
LONG
	);

        set("no_fight", 1);
	set("no_sleep_room", 1);
	set("no_update", 1);
        set("valid_startroom", 1);
        set("objects", ([
		__DIR__"npc/yuzu2" : 1,
	]));
	setup();
}
//
//void init()
//{
//	object me = this_player();
//        if (me->query_temp("nude"))
//        	call_out("do_succor",90,me);
//        else if(userp(me)) {
//        	me->move("/d/city/dilao");
//        	tell_object(me,"����߲�ͣ����һ���������²�Ϊ�����²�Ϊ������");
//        }
//        
//}

int do_kill(string arg)
{
        string action = query_verb();
        switch (action) {
        case "kill":
        case "hit":
        case "throw":
        case "fight":
        case "perform":
        case "dazuo":
        case "exercise":
        case "tuna":
        case "lian":
        case "practice":
        case "du":
        case "study":
        case "respirate":
        write("���Ѿ�������ط��ˣ�������Щ������ʲô��\n");
        return 1;
        }
	return 0;
}
void do_succor(object me)
{
	if (!me) return;
        message_vision(HIW"ͻȻ���洫��һ��������$N���Ŵ��㱼����Ȼ�а��绯����Ҳ�Ѿ��յ��ͷ�����ξ����������»ؾ�û��ô���ˡ���\n"NOR, me);
	tell_object(me,CYN"�������������������Ļ�����"NOR);
	me->delete_temp("nude");
	me->move("/d/city/dilao");

}
