// /d/city/kongchang

inherit ROOM;
#include <ansi.h>
#include <guanfu.h>
#include "/clone/npc/tdh/skill.h"

void create()
{
	set("short", "�㳡");
	set("long", @LONG
����֪���Աߵ�һƬС�ճ����ڶ��ߵ�ǽ�����˼��Źٸ�����׽�ó�͢Ҫ
���ĸ�ʾ (wanted list)������Χ������࿴���ֵ��ˣ����в���һЩ���ָ�
�֣�����Ҫ׽�õ�Ҫ���������֣������������Ұ�(jie)�� ��Ҳ�в�������
����֮����һ��ԾԾ���ԡ�
LONG
	);
	set("outdoors", "����");
	set("item_desc", ([
		"wanted list" : (: GF_WANTED->look_wanted() :),
	]));
	set("exits", ([
		"southwest" : __DIR__"guangchangbei",
	]));

	set("incity",1);
	setup();
	call_out( (:call_other:), 1, GF_WANTED, "???");
}

void init()
{
	if( this_player()->query_condition("killer") )
		return;
	add_action("do_jie", ({"xian","jie"}));

	if ( this_player()->query("gf_job")){
		this_player()->add("job_time/�ٸ�", this_player()->query("gf_job"));
		this_player()->delete("gf_job");
	}
}

int do_jie(string arg)
{
	object ob;
	if ( this_player()->query_temp("no_guanfu"))
		return notify_fail("�����ڲ��ܽ����顣\n");
	if ( this_player()->query_temp("��ػ�job")) {
		message_vision(HIY"$N���ָ�Ҫ�Ұ񣬶���ֻ����һ������ػᷴ���������ߣ���ͻȻ�ڳ�һ����Ӱֱ����$N��\n", this_player());
		ob = new("/clone/npc/tdh/bing");
		copy_npc(this_player(), ob, 150);
		ob->move(environment(this_player()));
		ob->kill_ob(this_player());
		this_player()->set_temp("no_guanfu", 1);
		return 1;
	}
	this_player()->set_temp("guanfu_jiebang", 1);
	return GF_WANTED->do_jie(arg);
}
