inherit NPC;
string ask_tea();
void create()
{
	set_name("СѾ��",({"xiao yahuan","xiao","yahuan"}));
       	set("long", "����һ��ʮ������СѾ�ߣ�����ü��Ŀ�㡣\n");
	set("gender", "Ů��");
	set("age", 10+random(6));
	set("attitude", "friendly");
	set("no_quest", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);	
	set("score", 500);
	setup();
        carry_object(ARMOR_D("pink_cloth"))->wear();
}
