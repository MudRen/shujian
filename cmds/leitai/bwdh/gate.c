//�Խ�ɽׯ  gate.c

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
	set("short",HIY"ׯԺ"NOR);
	set("long", @LONG
�����ׯԺ�����������µ��Խ�ɽׯ�ˣ��㲻������һ������ǰ��ɽׯ�ĵ�
�ϴ�ɨ��һ����Ⱦ�����������ɵ�̨�׺������ţ��ź�ľ���ƵĴ��Ž����ţ�ʹ
���޷���Ϥ���ڵ�һ�У����ɶ�ߵ�����ǽ��͸����Ҷ��������ҫ������������
�ž�������ֻ�ŵ�Զ���������������
LONG
	);
        set("exits", ([
		"north" : __DIR__"qianting",
		"out": __DIR__"zongtai",
	]));

	set("no_dig", 1);
	set("outdoors", "�Խ�ɽׯ");
	setup();
}

void init()
{
    object me = this_player();

    if(me->query("no_pk")){
        tell_object(me,BLINK + HIW"��ע�⣬���Ѿ�������"HIG"���Խ�ɽׯ��"HIR"����PK����"HIW"��ϵͳ�Զ���ʱɾ���������ϵ�ϴ��״̬!\n"NOR);
        tell_object(me,BLINK + HIC"�����뿪�Խ�ɽׯ��ϵͳ�����Զ�Ϊ���ָ�ϴ��״̬��\n"NOR);
        me->set("no_pk_recover",me->query("no_pk"));
        //����5����̽��ʱ��
        me->apply_condition("sjsz_time",15);
        me->delete("no_pk");
    }

    //ɾ����������ǡ�
    me->add_temp("get_in_sjsz",-1);

    return;
}
int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if( dir == "out") {
		while (i--)
		if( ob[i]->query("secret_obj"))
			return notify_fail("�������ô���صĶ��������뿪�Խ�ɽׯ�ǲ����ܵġ�\n");
	}

    if(dir == "out"){
      if(me->query("no_pk_recover")){
        tell_object(me,BLINK + HIG"���뿪���Խ�ɽׯ��ϵͳ�Զ��ָ�������ϴ��״̬��\n"NOR);
        me->set("no_pk",me->query("no_pk_recover"));
        me->delete("no_pk_recover");
      }
        me->clear_condition("sjsz_time");
    }

	return ::valid_leave(me, dir);
}
