// mabudai.c �鲼��

inherit ITEM;

void create()
{
	set_name("�鲼��", ({ "budai", "dai", "bag" }));
	set_weight(500);
	set_max_encumbrance(3000);
set("no_give",1);
set("no_cun",1);
set("no_drop",1);
set("no_steal",1);
        if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һֻ���鲼֯�ɵĴ��ӣ��������װ������\n");
		set("value", 500);
	}
}

int is_container() { return 1; }
