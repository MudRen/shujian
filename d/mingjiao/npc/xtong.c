inherit NPC;
string ask_tea();
void create()
{
	set_name("С��ͯ",({"xiao shitong","xiao","shitong"}));
       	set("long", "����һ��ʮ������С��ͯ������ü��Ŀ�㡣\n");
	set("gender", "����");
	set("age", 10+random(6));
	set("attitude", "friendly");
	set("no_quest", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);	
	set("score", 500);
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}
