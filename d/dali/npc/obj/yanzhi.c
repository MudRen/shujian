inherit ITEM;

void create()
{
	set_name( "��֬", ({ "yan zhi", "yanzhi" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��Ů�˻�ױ�õ���֬�� \n");
		set("value", 200);
		set("material", "iron");
	}
	setup();
}

