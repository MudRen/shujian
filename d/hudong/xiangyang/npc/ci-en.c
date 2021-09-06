// qqren.c 裘千仞

#include <ansi.h>
inherit NPC;

int ask_auto1();
int ask_auto2();

void create()
{
        set_name("慈恩", ({ "ci en", "qiu qianren", "qiu"}));
        set("long",
        "他身材矮小，留着一部苍髯，身披缁衣，相貌凶恶，眼发异光。\n"
        "出家前曾威震川湘，号称铁掌水上漂！\n");
        set("gender", "男性");
        set("age", 60);
        set("attitude", "peaceful");
        set("unique", 1);
        set("shen_type", 1);

        set("str", 35);
        set("int", 30);
        set("con", 28);
        set("dex", 35);

        set("max_qi", 9500);
        set("max_jing", 6000);
        set("max_neili", 16000);
        set("eff_jingli", 7500);
        set("jiali", 100);
        set("combat_exp", 4350000);
        set("score", 40000);

        set_skill("force", 340);
        set_skill("guiyuan-tunafa", 360);
        set_skill("dodge", 330);
        set_skill("shuishangpiao", 330);
        set_skill("strike", 370);
        set_skill("tiezhang-zhangfa", 370);
        set_skill("parry", 350);
        set_skill("literate", 180);
        set_skill("blade", 300);
        set_skill("liuye-daofa", 300);
        set_skill("tiezhang-xinfa", 200);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "tiezhang-zhangfa");
        map_skill("blade", "liuye-daofa");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhangdao" :),
                (: perform_action, "strike.tianlei" :),
                (: perform_action, "strike.judu" :),
                (: perform_action, "strike.heyi" :)
        }));
        set_temp("apply/armor", 80);
        set_temp("apply/damage", 80);
        set_temp("apply/attack", 80);

     
        set("inquiry", ([
                       "裘千仞" : "前尘往事，尽数糊涂，这个名字，不提也罢！\n",
                       "一灯大师" : (: ask_auto1 :),
                       "搭救" :     (: ask_auto2 :),
                          ]));
        setup();
       carry_object("/d/tiezhang/npc/obj/mayi")->wear();

}


int ask_auto1()
{
        object me = this_player(); 
 
        if( me->query_temp("quest/tzauto/dajiu") ==1 ) {
          command(" say 近来听闻蒙古大军将转攻大理，我因见师傅一灯大师心忧故国，故而前来打探消息，");
          command(" say 不想居然遇上蒙古国第一国师，我抵挡他不过，如今身负重伤，唉！");
          command(" sigh ");
          me->set_temp("quest/tzauto/qiu",1);
          me->delete_temp("quest/tzauto/dajiu");
        return 1;
}
        message_vision(CYN"慈恩道：“那是我师傅。”\n"NOR, me);
        return 1;

}

int ask_auto2()
{
        object me = this_player(); 
        if (me->query_temp("quest/tzauto/qiu") == 1)
          {
            command(" thank ");
            command(" say 当年我曾以为自己铁掌无敌，铁掌水上漂，哈哈！如今想来也不过是土鸡瓦狗。");
            command(" say 多谢搭救！在下还要回大理告知师傅蒙古军动向，就此别过！");
            command(" wave ");     
            message_vision(HIR"你细想刚才战斗经过，发现慈恩用的虽然是双掌，然而掌风霍霍，如同斧钺，心里似乎若有所悟。\n"NOR, me);             message_vision(HIR"你用手掌比划着裂天斧的招式。。。\n"NOR, me); 
            me->delete_temp("quest/tzauto/qiu");
            me->set("quest/tzauto/pass",1);
            me->move("/d/xiangyang/junying");
         return 1;
          }
       
      message_vision(CYN"慈恩奇怪的问道：“你要救谁？”\n"NOR, me);
      message_vision(CYN"你心下大窘，赶忙跑了出去。\n"NOR, me);
      me->move("/d/xiangyang/junying");
      return 1;
}