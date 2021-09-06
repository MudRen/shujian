// /kungfu/class/emei/wen-fei.c
// Lklv 2001.10.18 update

inherit NPC;
int ask_for_saomu();
void create()
{
        set_name("�ķ�Сʦ̫", ({ "wen fei", "wenfei", "shitai" }));
        set("long","���Ǹ����䲻��ü��Ŀ���Сʦ̫������ר�ſ��ع���Ĺ�ĵ��ӡ�\n");
        set("gender", "Ů��");
        set("attitude", "friendly");
	set("unique", 1);
        set("no_quest",1);
        set("class", "bonze");

        set("age", 19);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 0);
        set("combat_exp", 60000);
        set("score", 100);

	set_skill("dacheng-fofa", 60);
	set_skill("linji-zhuang", 60);
	set_skill("huifeng-jian", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("anying-fuxiang", 60);
        set("inquiry",([
                "ɨĹ"  : (: ask_for_saomu :),
        ]));

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
        create_family("������", 5, "����");

        setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();

}

int ask_for_saomu()
{
	object me = this_player();
	command("say ����̫���ˣ�����԰��Ұ�Ĺ�ԵĲ�����һ�¡�");
	me->set_temp("sao_mu", 1);
	return 1;
}
