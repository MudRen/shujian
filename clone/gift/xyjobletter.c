// letter_guo.c   for guo jing  Create by lsxk@hsbbs 2007/7/10

#include <ansi.h>

inherit ITEM;
void create()
{
  if(!random(2)){
    set_name(HIW "�����غ�" NOR, ({"xiangyang mihan","mihan","letter"}));
    set("long",
    WHT"����һ���ܷ�ؽ��������غ���������б�Ҫ��������ĳλ������Ҫ���\n"NOR);
  }
  else{
    set_name(HIR "�ɹ��غ�" NOR, ({"menggu mihan","mihan","letter"}));
    set("long",
    RED"����һ���ܷ�ؽ����ɹ��غ���������б�Ҫ��������ĳλ�ɹŴ����\n"NOR);
  }
	if (clonep())
		set_default_object(__FILE__);
	else {
            set("value", 50000);
            set("unit", "��");
		set("no_drop", 1);
        	set("unique", 1);
        	set("treasure", 1);
	}
}
