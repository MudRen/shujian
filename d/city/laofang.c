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
��������������������ڽ����������š�͸��������ص����ţ�ż������һ��
���ߺ�������������������ʲô���ˡ�
LONG
	);

        set("no_fight", 1);
	set("no_sleep_room", 1);
	set("no_update", 1);
        set("valid_startroom", 1);
        set("objects", ([
		__DIR__"npc/yuzu" : 1,
	]));
	setup();
}

void init()
{
	object me = this_player();
	if (userp(me) && !wiz_level(me) && !me->query_condition("killer"))
		me->apply_condition("killer", 2);
        if (me->query("succor"))
        	call_out("do_succor",1,me);
}

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
	message_vision(HIW"ͻȻ���洫��һ��ɱ������һ�����Ŵ󿪡�$N���˽����е������ֵܣ����ߡ���ػ�������ˣ���\n"NOR, me);
	set("exits/east", __DIR__"dilao");
	me->delete("succor");
	remove_call_out("do_close");
        call_out("do_close", 20, me);
}
void do_close(object me)
{
	if (me) message_vision(HIB"�η������ŷ���һ���������Լ������ˡ�\n"NOR, me);
	delete("exits");
}
