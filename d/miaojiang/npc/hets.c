// he  ������

inherit NPC;
void create()
{
       set_name("������", ({ "he tieshou", "he" }));
       set("title", "�嶾����");
       set("long", 
               "�������嶾���������֣�ȴ��һλ������ò��Ů�ӡ�\n"
               "һ����ԭŮ�ӵķ��Σ�������¶��һ˿�����\n");
        set("gender", "Ů��");
       set("age", 29);
       set("attitude", "friendly");
       set("shen", -10000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
       
       set("max_qi", 2000);
       set("max_jing", 1200);
       set("neili", 3000);
       set("max_neili", 3000);
       set("eff_jingli", 2500);
       set("jiali", 100);
       set("combat_exp", 1500000);
 
       set_skill("force", 160);
        set_skill("yinyun-ziqi", 160);
       set_skill("dodge", 160);
       set_skill("jinshe-zhangfa", 160);
       set_skill("tiyunzong", 160);
       set_skill("strike", 160);
       set_skill("jinshe-jianfa", 160);
       set_skill("parry", 160);
       set_skill("sword", 160);
       set_skill("poison", 120);
       set_skill("literate", 100);
        map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "jinshe-zhangfa");
       map_skill("parry", "jinshe-jianfa");
       map_skill("sword", "jinshe-jianfa");
       prepare_skill("strike", "jinshe-zhangfa");

       set("inquiry", ([
//               "�ؼ�" : (: ask_me :),
               "Ԭ��־" : "��Զ�����ൺ����Щ�����þ�û�������ˡ�",
               "��ɳ��Ӱ" : "������������İ�����",
               "���аٱ�" : "������õ��Ṧ����Ҳ������ѧ��һЩƤë���ѡ�",
       ]));

       setup();
       carry_object("/clone/weapon/changjian1")->wield();
       carry_object(__DIR__"obj/shoe")->wear();
       carry_object(__DIR__"obj/red_silk")->wear();
       carry_object(__DIR__"obj/skirt")->wear();
}
