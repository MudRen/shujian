inherit ITEM;
void create()
{
	set_name("�����׼�", ({ "head"}));
	set_weight(7500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "meat");
	}
	set("value", 1);
	if (clonep())
		call_out("decay", 360, 1);
	setup();
}

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	switch(phase) {
		case 1:
			say( query("name")+"��ʼ�𽥸����ˣ�����һ�����ŵĶ����\n");
			delete_temp("apply");
			set_name("���õ���ͷ", ({ "head" }));
			set("long", "����һ�Ÿ����˵���ͷ����ɢ����һ�ɸ�ʬ��ζ����\n");
			delete("victim_user");  
			delete("kill_by");
			delete("value");
			call_out("decay", 60, phase + 1);
			break;
		case 2:
			say( query("name")+"���紵���ˣ����һ�����á�\n" );
			set_name("����", ({ "skull" }) );
			set("long", "����һ����������á�\n");
			call_out("decay", 60, phase + 1);
			break;
		case 3:
			say( "һ��紵������"+query("name")+"���ɻҴ�ɢ�ˡ�\n");		       
			destruct(this_object());
	}
}
