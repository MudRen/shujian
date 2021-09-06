inherit NPC;

void create()
{
        set_name("����Ƽ", ({ "wanyan ping","wanyan","ping" }) );
        set("gender", "Ů��" );
        set("age", 26);
        set("long", "����Ŀ�������������Ʒ��Ĵ��ˡ�\n");
        set("attitude", "friendly");
        set("str", 35);
        set("con", 30);
        set("int", 20);
        set("dex", 30);
 

        set("max_qi", 6500);
        set("max_jing", 6500);
        set("neili", 6000);
        set("eff_jingli", 6500);
        set("max_neili", 7000);
        set("jiali", 100);
         
        set("combat_exp", 1000000);

        set_skill("force", 160); 
        set_skill("strike", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("guiyuan-tunafa", 160);
        set_skill("literate", 160);
        set_skill("tiezhang-zhangfa", 160); 
        set_skill("shuishangpiao", 160);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "tiezhang-zhangfa");
        prepare_skill("strike", "tiezhang-zhangfa");

        create_family("���ư�", 16, "����");

        setup();
        carry_object("/d/city/obj/cloth")->wear();
         
}
