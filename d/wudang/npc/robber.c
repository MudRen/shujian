inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>

int do_kill(object me);

string *sword_skill = ({ 
"taiji-jian","damo-jian","fumo-jian","jinshe-jianfa","qingmang-jianfa","yuxiao-jian",
"yunu-jianfa","songshan-jian","murong-jianfa","huashan-jianfa", "duanjia-jianfa",
"huifeng-jian","liangyi-jian","quanzhen-jianfa" }); 

string *blade_skill = ({ 
"cibei-dao","fanliangyi-dao","liuhe-daofa","murong-daofa","qingmang-jianfa","wenjia-daofa", 
"shandian-daofa","xiuluo-dao","xuanxu-daofa", "yanxing-daofa",}); 

string *staff_skill = ({ "wuchang-zhang","fengmo-zhang","tianshan-zhang","xinyuegong" }); 

string *club_skill = ({ "weituo-chu","zui-gun","weituo-gun","xinyuegong" }); 

string *whip_skill = ({ "piaomiao-bianfa","qingxu-bian" }); 

string *dodge_skill = ({ 
"shuishangpiao","suibo-zhuliu","yanling-shenfa","yufeng-xiang","tianlong-xiang",
"yunu-shenfa","zhaixingshu","xiaoyaoyou","zhongyuefeng","huashan-shenfa","tiyunzong" }); 

string *weapon_list = ({ "chui","sword","blade","whip","gun","sword","gangzhang","blade" }); 

string *first_name = ({ "�ݿ�","կ��","���","��å","ɽ��","����","����","��Ʀ","����","����"}); 

void create()
{
        string s_sword,s_blade,s_club,s_whip,s_staff,s_dodge, weapon, name;        
        name = first_name[random(sizeof(first_name))];
        s_sword = sword_skill[random(sizeof(sword_skill))];
        s_blade = blade_skill[random(sizeof(blade_skill))];
        s_club  = club_skill[random(sizeof(club_skill))];
        s_whip  = whip_skill[random(sizeof(whip_skill))];
        s_staff = staff_skill[random(sizeof(staff_skill))];
        s_dodge = dodge_skill[random(sizeof(dodge_skill))];
        weapon = weapon_list[random(sizeof(weapon_list))];

        set_name(name, ({ "robber"}));
        set("gender", "����");
        set("age", 20 + random(40));
        set("long", "��һ�һ�������ɷ��ģ����ʱ��ʱ����а�����Ц��\n");
        set("combat_exp", 800000);
//        set("meitude", "aggressive");
        set("meitude", "peaceful");
        set("str", 20);
        set("dex", 20);
        set("int", 20);
        set("con", 20);
        set("max_qi", 20000);
        set("max_jing", 20000);
        set("max_neili", 5000);
        set("neili", 5000);
        set_skill("huagu-mianzhang", 500);
        set_skill("strike", 500);
        set_skill("xinyuegong", 500);
        set_skill("yinyun-ziqi", 200);
        set_skill("sword", 500);
        set_skill("dodge", 500);
        set_skill("cuff", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("blade", 500);
        set_skill("hammer", 500);
        set_skill("club", 500);
        set_skill("staff", 500);
        set_skill("whip", 500);
        set_skill(s_sword, 500);
        set_skill(s_blade, 500);
        set_skill(s_club, 500);
        set_skill(s_whip, 500);
        set_skill(s_staff, 500);
        set_skill(s_dodge, 500);
        map_skill("force", "yinyun-ziqi");
        map_skill("sword", s_sword);
        map_skill("dodge", s_dodge);
        map_skill("parry", "taizuquan");
        map_skill("hammer", "xinyuegong");
        map_skill("blade", s_blade);
        map_skill("club", s_club);
        map_skill("whip", s_whip);
        map_skill("staff", s_staff);
        map_skill("strike", "huagu-mianzhang");
        prepare_skill("strike", "huagu-mianzhang");
        prepare_skill("cuff", "taizuquan");         
        setup();
        carry_object(BINGQI_D(weapon))->wield();
        carry_object(ARMOR_D("yexing-yi"))->wear();
        add_money("silver", random(10));
        set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :)
        }) );
        this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 600);

}       
void init()
{
        object ob;
        
        ::init();
        
        if( interactive(ob = this_player()) )
        {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}

void greeting(object ob)
{
        object me = this_object();
        
        if (!ob || !present(ob, environment()) || me->query_temp("target") != ob->query("id") ){
           remove_call_out("dest");
            call_out("dest",600);
            return;
            }
        
        if (ob->query("wd/wd_job"))
        {
        if (me->query_temp("target")!=ob->query("id"))
                        return;
                 else{
        message_vision(HIR""+me->name()+"����$N����һ����Ц��˵������Ȼ�������" + RANK_D->query_rude(ob)+ "ײ���ˣ���Ҳ��ֻ�����������ˣ�\n\n"NOR,ob);
                        ob->start_busy(1+random(2));
                        remove_call_out("checking");
                        call_out("checking", 1, me, ob);
                        remove_call_out("dest");
                        call_out("dest",200);
                        remove_call_out("do_kill");
                        call_out("do_kill", 0, ob);
                     }
        }
        return;
}



int do_kill(object ob)
{
        mapping skills;
        string *sk;
        object me; 
        int lv,exp,i,b_exp;
        me=this_object();
        lv=(int)ob->query("max_pot");
        lv = lv-100;
        exp = ob->query("combat_exp");
        b_exp=300000;
        
        if (exp<300000)
         {
            me->set("combat_exp",exp);
	    lv=lv*(random(3)+6)/10;
	 } else {
	me->set("combat_exp",(exp+random(20000*(exp/b_exp))));
        lv=lv*(random(3)+8)/10;
        }     
        me->set("qi",(int)ob->query("max_qi"));
        me->set("max_qi", (int)ob->query("max_qi"));
        me->set("eff_qi", (int)ob->query("max_qi"));
        me->set("jing",(int)ob->query("max_jing"));
        me->set("max_jing",(int)ob->query("max_jing"));
        me->set("eff_jing",(int)ob->query("max_jing"));
        me->set("neili",(int)ob->query("max_neili")*4/5);
        me->set("max_neili",(int)ob->query("max_neili") );
        me->set("jingli",(int)ob->query("max_jingli"));
        me->set("eff_jingli",(int)ob->query("max_jingli"));
        
        skills = me->query_skills();
        if (mapp(skills)) 
          {
                sk = keys(skills);
                for (i=0;i<sizeof(sk);i++)
                        skills[sk[i]] = lv;
          }
        me->kill_ob(ob);
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
      
}

void dest()
{
        object me,ob;
        ob = this_player();
        me = this_object();

//        write(me->query("name")+"����ææ�뿪�ˡ�\n");
        destruct(me);
}

void do_escape()
{
        object me,ob;
        me = this_object();
        ob = find_player(me->query_temp("target"));
        if(!ob) return;
        else if(!present(ob->query("id"),  environment(me) ) )
        {ob->set("wd/wd_job_lost2",1);
        tell_room(environment(me), me->query("name")+"ת��������Ͳ����ˡ�\n", ({me})); 
        destruct(me);
        return;
            }
      else
        {
         ob->set("wd/wd_jobok",1);
         tell_room(environment(me), me->query("name")+"ת��������Ͳ����ˡ�\n", ({me})); 
         destruct(me);
return;
         }
        return;
}
void do_lost()
{
        object me,ob;
        me = this_object();
        ob = find_player(me->query_temp("target"));
        if(!ob) return;
        ob->set("wd/wd_job_lost",1);
        tell_room(environment(me), me->query("name")+"ת��������Ͳ����ˡ�\n", ({me}));    
        destruct(me);
}

void kill_ob(object ob)
{
        object obj;
        obj = this_object();
        if(!ob) return;
     else
        if(obj->query_temp("target")!=ob->query("id"))
       {
         ob->set("wd/wd_job_lost2",1);
         tell_room(environment(obj), obj->query("name")+"���µ����ú�������ǰ����������\n", ({obj}));    
         tell_room(environment(obj), obj->query("name")+"ת��������Ͳ����ˡ�\n", ({obj}));    
         destruct(obj);
       }
        ::kill_ob(ob);
}
void unconcious()
{
        remove_call_out("do_escape");
        call_out("do_escape", 0);
//        ::unconcious();
}
int checking(object me, object ob)
{
        if(!me) return 0;
       if((!me->query("qi")>=me->query("max_qi")/2)&&(me->query_temp("cure")<2))
          {
           me->add("qi",me->query("max_qi")/4);
           me->add_temp("cure",1);
           tell_room(environment(me), me->query("name")+"��������˿�������ɫ��ʱ������ࡣ\n", ({me})); 
           }
        if(!ob || environment(ob)!= environment(me))
         {
           remove_call_out("do_lost"); 
           call_out("do_lost",0);
           return 1;
         }
        
        if ( me->query("qi")<me->query("max_qi")/10
          || me->query("eff_qi")<me->query("max_qi")/4 )
          { me->unconcious();
            return 1;}
          else if(ob->is_fighting())
         {
           remove_call_out("checking");
           call_out("checking", 1, me, ob);
           return 1;
         }
        else if(!me->is_killing(ob->query("id")) ) 
         {
           me->kill_ob(ob);
           remove_call_out("checking");
           call_out("checking", 1, me, ob);
           return 1;
         }
        return 1;
}

int hit = 0;

int ob_hit(object me, object ob, int damage)
{
        int exp = me->query("combat_exp")/1000000;
        if ( exp > 9 ) exp = 9;
        if (!hit) return -damage*(10-exp)/10;
        hit--;
        return 0;
}
