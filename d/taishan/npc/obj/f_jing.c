//  fanwen jinggangjing
// by dubei

inherit ITEM;

void create()
{
	set_name("���Ľ�վ�", ({ "fanwen jing", "fanwen", "jing"}));
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"����һ������׭д�ľ��飬����д�����������С�֡�\n");
		set("value", 10000);
		set("material", "paper");
              set("treasure",1);
	}
}
 
