void create()
{
	set_name("��ʯ", ({ "kuangshi" , "shi" }));
	set_weight(3000+random(5000));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�Ŀ�ʯ��\n");
		set("value", 3000);
		set("kuangshi",1);
	}
	setup();
}
