// NPC: /d/huashan/npc/laodenuo.c
// Date: Look 99/03/25
// Lklv Modify at 2001.10.18
// By Spiderii@yt�޸�ٺ»
inherit NPC;

#include <ansi.h>

string ask_me(object who);
//int ask_gold(object who);

void create()
{
        set_name("�͵�ŵ", ({ "lao denuo", "lao", "denuo" }));
        set("nickname", "�Ϻ���");
        set("long",
"�͵�ŵ��İ��֣������⣬����Ц���еģ�����\n"
"ͬ�������еڶ����ǻ�ɽ������һ����Ψһ����Ͷʦ�ġ�\n");
        set("gender", "����");
        set("age", 54);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 24);
        set("per", 18);
        set("int", 25);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 30000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("eff_jingli", 1800);

        set("jiali", 50);
        set("combat_exp", 600000);
        set("score", 6000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("cuff", 100);
        set_skill("hand", 100);
        set_skill("songshan-jian", 100);
        set_skill("huashan-jianfa", 100);
        set_skill("huashan-shenfa", 100);
        set_skill("poyu-quan", 100);
        set_skill("hanbing-zhenqi", 100);
        set_skill("songyang-shou", 100);
        set_skill("zhengqi-jue", 100);
        set_skill("zixia-gong", 100);

        map_skill("hand", "songyang-shou");
        map_skill("dodge", "huashan-shenfa");
        map_skill("force", "zixia-gong");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("cuff", "poyu-quan");

  
        set("inquiry", ([
              "��ϼ�ؼ�"   : (: ask_me :),
                //"������" : (: ask_gold :),
        ]) );

        create_family("��ɽ��", 14, "����");

        setup();
        carry_object(BINGQI_D("sword/sword"))->wield();
        carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_me(object who)
{
        int i;
        object *ob,book;

        if( (random(10) < 8) || is_fighting() )
                return "�Բ�������£��Ҳ�������㻹������ʦ��ȥ�ɣ�\n";
        set_temp("apply/attack",  500);
        set_temp("apply/defense", 500);
        set_temp("apply/damage",  500);
      
        
   
        set("neili", 60000);
        set("max_neili", 30000);
        set("eff_jingli", 8000);
        set("jingli",8000);
        set("jiali", 150);
        
        set("combat_exp",8000000);


        set_skill("force", 400);
        set_skill("songshan-qigong", 400);
        set_skill("dodge", 400);
        set_skill("zhongyuefeng", 400);
        set_skill("strike", 390);
        set_skill("songyang-zhang", 390);
        set_skill("parry", 390);
        set_skill("sword", 390);
        set_skill("songshan-jian", 395);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 450);
        map_skill("force", "hanbing-zhenqi");
        map_skill("dodge", "zhongyuefeng");
        map_skill("strike", "hanbing-shenzhang");
        map_skill("parry", "songshan-jian");
        map_skill("sword", "songshan-jian");

      prepare_skill("strike", "hanbing-shenzhang"); 



        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "strike.hanbing" :),
                (: exert_function, "juhan" :),
                (: random_move :),
        }));


        set("chat_chance", 70);
        set("chat_msg", ({
                (: random_move :)
        }) );

        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !userp(ob[i]) ) continue;
                if( ob[i]->query_temp("hs/askzixia",1) && ob[i]->query("quest/zixia/pass"))
                        {
                         ob[i]->delete_temp("hs/askzixia");
                        book = unew(__DIR__"obj/zixia");
                        if( clonep(book) ) {
                        book->move(this_object());
                        }
                  }
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
               
       message("vision",
                YEL "����������㶼֪���ˣ�������ȥ���ɣ�\n"
                "�͵�ŵʹ���������������棬�����ޱȣ�һ������Ц�����ģ����\n" NOR,
                environment(), this_object() );
      
      
       return "�Ҵ���Ͷʦ�����踺�أ��㾹�Ҵ��ҵ����⣬ȥ���ɣ�\n";
                
        }
        
   
    
        return "�Բ�������£��Ҳ�������㻹������ʦ��ȥ�ɣ�\n";
}
