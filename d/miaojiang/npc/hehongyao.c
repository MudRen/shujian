// hehongyao  �κ�ҩ

inherit NPC;
void create()
{
       set_name("�κ�ҩ", ({ "he hongyao", "he", "hongyao" }));
       set("nickname", "������");
       set("long", 
               "�����Ǻ����ֵ��������ֺκ�ҩ��\n"
               "���������ʮ���⣬һ˫�۾�͸�����⡣\n");
        set("gender", "Ů��");
       set("age", 59);
       set("attitude", "friendly");
       set("shen", -3000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
       
       set("max_qi", 1200);
       set("max_jing", 1000);
       set("neili", 1800);
       set("max_neili", 1800);
       set("eff_jingli", 1400);
       set("jiali", 70);
       set("combat_exp", 800000);
 
       set_skill("force", 130);
        set_skill("yinyun-ziqi", 130);
       set_skill("dodge", 130);
       set_skill("jinshe-zhangfa", 130);
       set_skill("tiyunzong", 130);
       set_skill("strike", 130);
       set_skill("jinshe-jianfa", 130);
       set_skill("parry", 130);
       set_skill("sword", 130);
       set_skill("poison", 80);
       set_skill("literate", 100);
        map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "jinshe-zhangfa");
       map_skill("parry", "jinshe-jianfa");
       map_skill("sword", "jinshe-jianfa");
       prepare_skill("strike", "jinshe-zhangfa");

       set("inquiry", ([
              
               "Ԭ��־" : "�����ǳ���������",
               "��ɳ��Ӱ" : "�嶾�̵Ķ��Ű�����",
       ]));
       setup();
     
       carry_object("/clone/armor/cloth")->wear();
}
