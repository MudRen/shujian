// wu.c �⾢��
// Modify By River@sj 99.06
inherit NPC;
void create()
{
        set_name("�⾢��", ({ "wu jincao", "wu", "jincao" }));
        set("gender", "����");
        set("age", 43);                
	set("rank_info/respect","����");
	set("title","��������츱����ʹ");
        create_family("����", 37, "����");
	set("str", 28);
        set("int", 20);
        set("con", 23);
        set("dex", 22);
        set("per", 20);
        set("combat_exp", 145000);
        set("unique", 1);
        set("attitude", "peaceful");
	set("max_qi",1000);
        set("max_jing",1000);
        set("neili",1000);
        set("max_neili",1000);
        set("eff_jingli", 1000);
	set("jiali",30);
        set_skill("cuff", 60);
	set_skill("parry",60);
	set_skill("piaoyi-shenfa",60);
        set_skill("dodge", 60);
	set_skill("force",60);
	set_skill("shenghuo-shengong",60);
	map_skill("force","shenghuo-shengong");
	map_skill("dodge","piaoyi-shenfa");        
        set_skill("taizu-quan",60);
        map_skill("parry","taizu-quan");
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff","taizu-quan");            
        setup();
        carry_object("/d/mingjiao/obj/green-cloth")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say ���ڽ��·�æ��������ò��յ����ˡ�");
        command("say ��λ"+RANK_D->query_respect(ob)+"������ذɡ�");
        return;
}
