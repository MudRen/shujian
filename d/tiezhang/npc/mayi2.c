//mayi2.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
     object ob;
       set_name("������", ({"ling zhentian","ling","zhentian"}));
       set("title","���³���"); 
       set("nickname",HIY"������ӥ"NOR);
       set("long",
    "����һ����Լ��Ѯ�����ߣ���ͷ���������ް߰ס�\n"
    "�������̫��Ѩ�߸߹���΢�յ�˫Ŀ��ʱ�����������������ƺ���������\n"
       );

       set("gender", "����");
       set("attitude", "peaceful");
       set("unique", 1);
       set("age", 60);
       set("shen_type", -10);
       set("str", 28);
       set("int", 23);
       set("con", 23);
       set("dex", 28);
       set("per", 20);
       set("max_qi", 1500);
       set("max_jing", 1000);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 50);
       set("combat_exp", 500000);
       set("score", 10000);

       set_skill("force", 120);
       set_skill("guiyuan-tunafa", 120);
       set_skill("dodge", 120);
       set_skill("literate", 100);
       set_skill("shuishangpiao", 120);
       set_skill("strike", 120);
       set_skill("tiezhang-zhangfa", 100);
       set_skill("parry", 120);
       set_skill("axe", 130);
       set_skill("lietian-fu", 140);
        set_skill("tiezhang-xinfa", 120);

       map_skill("force", "guiyuan-tunafa");
       map_skill("dodge", "shuishangpiao");
       map_skill("strike", "tiezhang-zhangfa");
       map_skill("parry", "tiezhang-zhangfa");
       map_skill("axe", "lietian-fu");
       prepare_skill("strike", "tiezhang-zhangfa");

       create_family("���ư�", 15, "����");
       setup();
        if (clonep()) {
       ob = unew("/d/tiezhang/obj/yuanyang-yue");
       if (ob) {
                destruct(ob);
                ob = unew("/d/tiezhang/obj/wanzi-duo");
                }
       if (!ob) ob = unew("/d/tiezhang/obj/gangfu");
                ob->move(this_object());
                ob->wield();
                carry_object("/d/tiezhang/npc/obj/mayi")->wear();
        }

}

void init()
{
       object me, ob;
       mapping fam;

       ::init();

       ob = this_player();
       me = this_object();
       
       if (interactive(ob) 
       && !environment(ob)->query("no_fight")
       && ( (fam = ob->query("family")) && fam["family_name"] != "���ư�" ) 
        && (int)ob->query("combat_exp", 1) >= 10000 ) 
       {
               if( !ob->query_temp("warned") ) {
        command("say վס���㲻�����ư���ӣ������ڴ˾�������");
        command("say �㻹�������뿪�˵ذɣ���Ȼ�����Ҫ���㲻�����ˣ���");
        command("hehe");
                       ob->set_temp("warned", 1);
               }
          else if( ob->query_temp("stay") < 3 ) ob->add_temp("stay", 1);
                else {
                       command("say ���ò��ͷ��ˣ����ҵ����ư�����Ұ������\n");
                       remove_call_out("hiting_ob");
                       call_out("hiting_ob", 1, ob);
               }
       }       

}


int hiting_ob(object ob)
{
        object me;
        me=this_object();
        ob->kill_ob(me);
        me->fight_ob(ob);
}
