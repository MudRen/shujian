//  shusheng.c

inherit NPC;

void create()
{
	set_name("����", ({ "shu sheng", "student", "sheng", "shu" }));
	set("gender", "����");
	set("age",22);
	set("per", 26);
	set("long","����һ�����ݸ�����ţ��꼶���ᡣ�����������徭�⣬Ҳ�����Щ�������š�\n");

        set("chat_chance", 3);
       	set("chat_msg", ({
 		"����˵��������˵������������ѧ������߾����������ʤ�����ˡ���\n",
 		"����˵�������䵱ɽ�������������ǵ�������Ψһ����ѧ����ʦ����\n",
       	}) );
	set("combat_exp", 21000);
	set("shen", 20);
	set("attitude", "friendly");
	setup();
	carry_object(ARMOR_D("jinduan"))->wear();
}

