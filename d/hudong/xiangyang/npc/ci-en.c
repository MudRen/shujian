// qqren.c ��ǧ��

#include <ansi.h>
inherit NPC;

int ask_auto1();
int ask_auto2();

void create()
{
        set_name("�ȶ�", ({ "ci en", "qiu qianren", "qiu"}));
        set("long",
        "����İ�С������һ�����ף�������£���ò�׶��۷���⡣\n"
        "����ǰ�������棬�ų�����ˮ��Ư��\n");
        set("gender", "����");
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
                       "��ǧ��" : "ǰ�����£�������Ϳ��������֣�����Ҳ�գ�\n",
                       "һ�ƴ�ʦ" : (: ask_auto1 :),
                       "���" :     (: ask_auto2 :),
                          ]));
        setup();
       carry_object("/d/tiezhang/npc/obj/mayi")->wear();

}


int ask_auto1()
{
        object me = this_player(); 
 
        if( me->query_temp("quest/tzauto/dajiu") ==1 ) {
          command(" say ���������ɹŴ����ת�����������ʦ��һ�ƴ�ʦ���ǹʹ����ʶ�ǰ����̽��Ϣ��");
          command(" say �����Ȼ�����ɹŹ���һ��ʦ���ҵֵ�����������������ˣ�����");
          command(" sigh ");
          me->set_temp("quest/tzauto/qiu",1);
          me->delete_temp("quest/tzauto/dajiu");
        return 1;
}
        message_vision(CYN"�ȶ�������������ʦ������\n"NOR, me);
        return 1;

}

int ask_auto2()
{
        object me = this_player(); 
        if (me->query_temp("quest/tzauto/qiu") == 1)
          {
            command(" thank ");
            command(" say ����������Ϊ�Լ������޵У�����ˮ��Ư���������������Ҳ�����������߹���");
            command(" say ��л��ȣ����»�Ҫ�ش����֪ʦ���ɹž����򣬾ʹ˱����");
            command(" wave ");     
            message_vision(HIR"��ϸ��ղ�ս�����������ִȶ��õ���Ȼ��˫�ƣ�Ȼ���Ʒ��������ͬ���ᣬ�����ƺ���������\n"NOR, me);             message_vision(HIR"�������ƱȻ������츫����ʽ������\n"NOR, me); 
            me->delete_temp("quest/tzauto/qiu");
            me->set("quest/tzauto/pass",1);
            me->move("/d/xiangyang/junying");
         return 1;
          }
       
      message_vision(CYN"�ȶ���ֵ��ʵ�������Ҫ��˭����\n"NOR, me);
      message_vision(CYN"�����´󾽣���æ���˳�ȥ��\n"NOR, me);
      me->move("/d/xiangyang/junying");
      return 1;
}