#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","��ɽ");
        set("long", @LONG
�������죬�����ܲ���һ��С�ľͻᱻ�ҵ����ֽš�Ũ�ܿ�����Ҷ�ڱ�
�������ǳ�����������ɢ���Ų����˲ȹ��Ľ�ӡ��������һ��ļž���ֻ�з�
�������ҵ�ɳɳ֮������������˸��ֶ��棬�㲻������������֮�ġ�
LONG                           
        );

        set("exits", ([
                "southeast" : __DIR__"shanlu",
        ]));
        set("objects", ([
              __DIR__"npc/yan-ji" :1,
        ]) );
        set("outdoors", "�置");
        setup();
}
void init()
{
        add_action("do_find", "find");
}
int do_find(string arg)
{
        object me = this_player();

        if(!arg ||arg != "snake") 
        	return notify_fail("���ڸ���\n");
        if (!me->query("gb/snaked")|| me->query("gb/found"))
        	return notify_fail("�����\n");
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	message_vision("$N����һ�Դ��Ӳݣ���ϸ��Ѱ�š�\n", me);
        me->start_busy(2);
        if (random(me->query_int())>20){
        	remove_call_out("happen1");
        	call_out("happen1", 1, me);
        	return 1;
        }
        if ( random((int)me->query("snake_job"))>1000){
        	remove_call_out("happen2");
        	call_out("happen2", 1, me);
        	return 1;
        }
	return 1;
}
int happen1(object me)
{
        message_vision("$N��ǰһ�������ֲݴ���·���ʲô�����ڶ�����æ������ϸ���ơ���\n",me);
	if(random(me->query("kar"))>15){
		message_vision("$N������ϲ�����ּ���һ����ʯ��\n",me);
		new(MISC_D("yushi"))->move(me);
		return 1;
	}
	if(random(me->query("int"))>10){
		remove_call_out("happen3");
		call_out("happen3", 1, me);
		return 1;
	}

	message_vision("$Nʹ���������۾���ԭ�����ۻ��ˡ�\n",me);
	return 1;
}
int happen2(object me)
{

        if (NATURE_D->query_daytime() == "event_noon"){
    		message_vision("$N������ϲ�����ּ���һ��𶧡�\n",me);
		new("/clone/money/gold")->move(me);
		return 1;
	}
	if(random(me->query("int"))>10){
		remove_call_out("happen3");
		call_out("happen3", 1, me);
		return 1;
	}
	message_vision("$N���˰��죬ʲôҲû���֣����ɵؾ�ɥ��̾�˿�����\n",me);
	return 1;
}

int happen3(object me, object snake)
{
        
        message_vision("$N��Ȼ���˵��������������һ�����������ܣ������Ҵ����ˣ���\n",me);
	message_vision("$N������סһ��С�ߵ�β�ͣ�����ץ��������\n",me);
	snake = new("/clone/animal/gbsnake");
        snake->set("name",me->query("name")+"����");
	snake->set_temp("owner",me->query("id"));
	snake->move(me);
	if (!wizardp(me))
	me->set("gb/found",1);
	return 1;
}
