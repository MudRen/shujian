inherit ITEM;

void create()
{
	set_name( "����", ({ "hua fen", "fen" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ�в��������õĻ��ۡ� \n");
		set("value", 250);
		set("material", "iron");
	}
	setup();
}

