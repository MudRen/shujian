// yayi.c  �ٸ�����

inherit NPC;
void create()
{
        object ob;
        set_name("������", ({ "da yayi", "yayi", "dayayi", "ya yi" }));
        set("gender", "����");
        set("age", 30);

        set("long", "һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣\n");
        set("combat_exp", 800000);
        set("max_neili",2000);
        set("max_qi",1500);
        set("eff_jingli",1000);
        set("max_jing",1000);
        set("neili",2000);
        set("qi",1500);
        set("jingli",1000);
        set("jing",1000);
        set("shen_type", 1);

        set_skill("stick", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set("chat_chance", 2);
        set("inquiry", ([
		"����" : "�ǻ����򵥣���ֻҪ�е��������������(jie wenshu)��Ȼ���Ŀ��ɱ�˾Ϳ��ԡ�",
	]));
	set("chat_msg", ({
		"������С���ֹ�������������˵����֮�в����Ի���Ҳ��֪�������Ǽ٣���\n",
		"����������˵��������·Ӣ�ۣ�����Ŀǰ����׽�ý�����������λ��Э���ٸ���������ͽ����\n",
	}));
	setup();
	carry_object("/d/city/npc/obj/yayifu")->wear();
	if(clonep()) {
		ob = unew(BINGQI_D("shawei-bang"));
		if(ob) {
		ob->move(this_object());
		ob->wield();
		}
	}
}
