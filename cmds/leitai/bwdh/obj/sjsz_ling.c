//sjsz_ling.c  �Խ�ɽׯ����  by lsxk@hsbbs 2008/06/27

#include <ansi.h>
#include <combat.h>
inherit ITEM;

void create()
{
       set_name(HIY"�Խ���"NOR, ({ "shijian ling","ling"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
               set("long",HIY"����һ���Խ�ɽׯ���Խ����˵����ʹ�ô�������ɽׯ��������ӭ�ͣ�\n"NOR);
		set("value", 0);
               set("treasure",1);
		set("material", "wood");
		set("no_drop",1);
	 }
}
