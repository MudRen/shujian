inherit NPC;
string ask_me();
void create()
{
	set_name("�������", ({ "xinqing biqiu","xingqing","biqiu"}) );
	set("long","���Ǹ�����С���ӣ�������������ʵ������΢Ц�š�\n");
	set("gender", "����" );
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 25);
	set("shen_type", 1);

	set("str", 23);
	set("int", 22);
	set("con", 24);
	set("dex", 24);
	create_family("������", 15, "����");
	set("inquiry",([
                "����" : (: ask_me :),
                "СС��" : "СС�����֣�",
        ]));

        set("qi", 600);
        set("max_qi", 600);
        set("jing", 500);
        set("eff_jingli", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);
        set("combat_exp", 200000);
        set("score", 10);

        set_skill("strike", 60);
        set_skill("force", 60);
        set_skill("qiantian-yiyang", 70);
        set_skill("dodge", 60);
        set_skill("qingyan-zhang", 70);
        set_skill("tianlong-xiang", 70);
        set_skill("parry", 70);
        set_skill("buddhism", 60);
        set_skill("literate", 60);
        map_skill("strike", "qingyan-zhang");
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "qingyan-zhang");
        prepare_skill("strike","qingyan-zhang");

        set("hammer_count", 1);  
        set("chat_chance", 3);
	set("chat_msg", ({
		"���������Ҫ�����ˣ��Ǻǣ�\n",
	})); 
	setup();
	carry_object("/d/tls/obj/jiasha1")->wear();
	carry_object("/d/tls/obj/sengxie")->wear();
}

string ask_me()
{
	mapping fam = this_player()->query("family");
	mixed *local;
	object ob;
	local = localtime(time() * 60);

	if(!fam || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

	if(this_player()->query_skill("force",1) < 30)
		return "����ڹ���Ϊ̫����Ӷ�����Ի��˺�����";

	if (local[2] < 6 || local[2] >= 21) 
		return "��������Ϣʱ���ˣ����볳�������";

	if(query("hammer_count") < 1)
		return "�������ˣ��Ѿ������������ˡ�";

	add("hammer_count", -1);
	ob = new("/d/tls/obj/zhongchui");
	ob->move(this_player());
	return "�ðɣ�������������ȥ���Ӱɡ�";
}

void reset()
{
	this_object()->set("hammer_count", 1);
}
