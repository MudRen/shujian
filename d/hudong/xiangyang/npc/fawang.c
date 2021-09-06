// by iceland

inherit NPC;
#include <ansi.h>
#include "boss.h"

int pfm_wushuai();
int pfm_riyue();


void create()
{
        object weapon;
        set_name("���ַ���", ({ "jinlun fawang", "jinlunfawang","fawang" ,"jinlun","fanfang"}));
        set("long",@LONG
����ĸ��ݣ��������ݣ�˫Ŀ������������̫��Ѩȴ�߸�͹���������ࡣ
���ܷ⡰�ɹŹ���һ��ʦ��������һ��ͨ�쳹�ص��񹦡�
LONG
        );
        set("title", HIY "�ɹŹ���һ��ʦ" NOR);
        set("gender", "����");
        set("class", "huanxi");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 34);
        set("per", 22);

        set("unique", 1);  //Ψһ��

        set("max_qi", 200000);
        set("max_jing", 20000);
        set("eff_jingli", 20000);
        set("neili", 200000);
        set("max_neili", 200000);
        set("jiali", 200);
        set("combat_exp", 10000000);
        
        set_skill("huanxi-chan", 200);
        set_skill("literate", 300);
        set_skill("force", 600);
        set_skill("longxiang-boruo", 600);
        set_skill("dodge", 600);
        set_skill("yuxue-dunxing", 600);
        set_skill("hammer", 600);
        set_skill("xiangfu-lun", 600);
        set_skill("hand", 600);
        set_skill("dashou-yin",600);
        set_skill("claw", 600);
        set_skill("tianwang-zhua", 600);
        set_skill("parry", 600 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hammer", "xiangfu-lun");
        map_skill("parry", "xiangfu-lun");
        map_skill("hand","dashou-yin");
        map_skill("claw","tianwang-zhua");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("������", 10, "����");
        set("inquiry", ([
               
                
       ]));
        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("max_cure",5);
        set_temp("��������/������ս/��Ӫ",2);

        set("class", "huanxi");
     
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: exert_function, "shield jinlun fawang" :),
                (: pfm_wushuai :),
                (: pfm_riyue :),
          //      (: perform_action, "hammer.wushuai" :), 
           //     (: perform_action, "hammer.riyue" :), 
          //      (: perform_action, "hammer.dazhuan" :), 
        }));

        set_temp("apply/damage", 500);
        set_temp("apply/dodge", 300);
        set_temp("apply/attack", 300);
        set_temp("apply/defence",500);

        setup();
        if (clonep()){
               
                weapon = unew(BINGQI_D("falun"));
                weapon->move(this_object());
         
                weapon->wield();
                carry_object("/d/xueshan/npc/obj/longxiang-jiasha")->wear();       
                add_money("gold",2);
        }
}

int pfm_wushuai()
{
        object me,weapon;
        me = this_object();
        weapon = present("falun",me);
        if( me->is_busy()) return 0;
        if( objectp(weapon)){
                set("jiali", 200);
                command("wield falun");
                command("perform wushuai");
                return 1;
        }
        else {
                new(BINGQI_D("falun"))->move(me);
                set("jiali", 200);
                command("wield falun");
                command("perform wushuai");
                if(random(10) > 5){
                        set("jiali", 200);
                //      command("unwield falun"); //ת����pfm
                }
                return 1;
        }
        return 1;
}

int pfm_riyue()
{
        object me,weapon;
        me = this_object();
        weapon = present("falun",me);
        if( me->is_busy()) return 0;
        if( objectp(weapon)){
                set("jiali", 200);
               
                command("wield falun");
                command("perform riyue");
                return 1;
        }
        else {
                new(BINGQI_D("falun"))->move(me);
        
                set("jiali", 200);
                command("wield falun");
                weapon = present("falun",me);
               
                command("perform riyue");
                if(random(10) > 5){
                        set("jiali", 200);
                //      command("unwield falun"); //ת����pfm
                }
                return 1;
        }
        return 1;
