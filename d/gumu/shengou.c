// Modify By River 98/08
// Modify By YUJ@SJ 2001-0609 ����ͨ����
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�"NOR);
	set("long", @LONG
�Ҵҵش������֣���ǰ����һ���(gou)����֪����Ȼ���ɽϪ�����ڣ�
��������ȥ·����ͷһ������������һ��ʯ��(shibei)��
LONG
     );

	set("exits", ([
	    "west" : __DIR__"shulin2",
	]));

	set("objects", ([
		CLASS_D("gumu") + "/sun" : 1,
	]));
	set("item_desc", ([
		"gou" : HIC"���������������Լ�к������ˣ�����ƺ�����Ʈ������������������˳�\n"+
			"Ȼ�����ĺ����ڣ�����Ȼ���������Խ�����һ��Ծ����(tiao)�µĳ嶯��\n"NOR,
		"shibei" : HIR"\t\t����ɽ������Ĺ������Ī�룡\n"NOR
	]));

	set("outdoors", "��Ĺ");

	setup();
}

void init()
{
	add_action("do_jump", "tiao");
}

int can_betray(object me)
{
	mapping skills = me->query_skills();

	if (sizeof(skills) < 1)
		return 1;
	foreach (string skill in keys(skills))
		if (SKILL_D(skill)->valid_enable("force"))
			return 0;
	return 1;
}

int do_jump(string arg)
{
	mapping fam;
	object me = this_player();
	object *inv;

	fam = me->query("family");
	if ( arg =="gou") {
		if (me->is_busy())
			return notify_fail("����æ���ء�\n");
		if ( fam && fam["family_name"] == "ȫ����") {
			write(HIR"��ʦ��ѵ�������𣿣�\n"NOR);
			me->unconcious();
			return 1;
		}
		if( me->query("gender") == "����") {
			write(HIR"�����ֲ��в�Ů�Ķ����������Ĺ��\n"NOR);
			me->unconcious();
			return 1;
		}
		if (me->query_condition("killer"))
			return notify_fail("�㻹���˽��꽭����Թ��˵�ɡ�\n");
		if ( fam && fam["family_name"] != "��Ĺ��" && !can_betray(me))
			return notify_fail(HIR"\t\t��Ĺ�صأ�����Ī�룡\n"NOR);
		if (!fam || fam["family_name"] != "��Ĺ��") {
			if (me->query("expell"))
				return notify_fail(HIR"\t\t��Ĺ�صأ�����Ī�룡\n"NOR);
			if (me->query_int() < 22)
				return notify_fail(HIR"������Ƿ��, ���½�����Բ˫���ϱ�֮���Ρ�\n"NOR);
			if (me->query_skill("literate", 1) < 20)
				return notify_fail(HIR"��Ķ���д��̫�ͣ����Ĺ�޷�����\n"NOR);
			if (me->query_dex() < 15 && me->query("gender") == "����")
				return notify_fail(HIR"����̫�ͣ�����ѧ���˹�ĹƮ��Ĺ���\n"NOR);
			if (me->query_dex() < 18 && me->query("gender") == "Ů��")
				return notify_fail(HIR"����̫�ͣ�����ѧ���˹�ĹƮ��Ĺ���\n"NOR);
			if (me->query("per") < 25)
				return notify_fail(HIR"��������òǷ��, ���½�����Բ˫���ϱ�֮���Ρ�\n"NOR);
		}
		inv = filter_array(deep_inventory(me), (: userp :));
		if (sizeof(inv)) {
			write(HIR"�㸺��̫�࣬����һ����˩��ˤ���ڵء�\n"NOR);
			me->unconcious();
			return 1;
		}
		tell_room(this_object(), HIM+me->name() + "΢һ������ƾ���ݸ����࣬�¾�ƮƮ����������������ɽ���С�\n", me);
		me->move(__DIR__"rukou");
		message_vision(HIY"$N���������������ǡ���ô����������ڹ�Ĺ���ǰ��\n"NOR, me);
		return 1;
	}
	return notify_fail("������������\n");
}
