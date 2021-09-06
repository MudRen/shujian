#include <ansi.h>

inherit NPC;
inherit F_MASTER;

#define TIME_TICK (time()*60)
string do_ask();
string do_cancel();
void create()
{
        object ob;
        
        set_name("������", ({ "zuo lengchan", "zuo", "lengchan" }));
        set("nickname", "������������");
        set("long", "��ɽ�������������ǵ����������˲��������书��Ȼ�����뻯��
Ϊ���ȸ����ǣ�����ٳ���������һ�ᵽ�������������֣��޲���Ȼ��\n");
        set("gender", "����");
        set("age", 52);
        set("per", 20);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 29);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 4300);
        set("max_jing", 2800);
        set("eff_jingli", 2300);
        set("jiali", 50);
        set("combat_exp", 1800000);
        set("shen", -18000);
        set("max_neili", 3500);
        set("neili", 3500);

        set_skill("force", 190);
        set_skill("songshan-qigong", 200);
        set_skill("dodge", 190);
        set_skill("zhongyuefeng", 190);
        set_skill("strike", 190);
        set_skill("songyang-zhang", 190);
        set_skill("parry", 190);
        set_skill("sword", 190);
        set_skill("songshan-jian", 195);
        set_skill("literate", 150);
        set_skill("hanbing-shenzhang", 200);
        map_skill("force", "songshan-qigong");
        map_skill("dodge", "zhongyuefeng");
        map_skill("strike", "hanbing-shenzhang");
        map_skill("parry", "songshan-jian");
        map_skill("sword", "songshan-jian");
        prepare_skill("strike", "hanbing-shenzhang");
        set("inquiry", ([
                "job": (: do_ask() :),
                "����": (: do_ask() :),
                "cancel": (: do_cancel() :),
                "����": (: do_cancel() :),
        ]));
        create_family("��ɽ��", 4, "������");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "strike.hanbing" :),
                (: exert_function, "jianqi" :),
        }));

        setup();
        if (clonep()) {                
                ob = unew(BINGQI_D("guanri-jian"));               
                if (!ob) ob = unew(BINGQI_D("gangjian"));
                ob->move(this_object());
                ob->wield();
                carry_object(ARMOR_D("changpao1"))->wear();
                carry_object(MEDICINE_D("tianwang"));
        }           
        add_money("gold", 2);
}

void attempt_apprentice(object ob)
{
     if(ob->query_skill("hanbing-zhenqi",1) < 160 ||
      ob->query_skill("songshan-jian",1) < 160 ||
        ob->query_skill("songyang-zhang",1) < 160){
        command("say ����书��������죬�ٻ�ȥ�����ɡ�");
        return;
        }
     if ((int)ob->query("songshan_points") < 250) {
                command("say ���Դ�������������͵��ˣ����������ҵ���������Ϊʦ��");
                return;}
     command("say �ã���������Щ������������ں������ƣ������㻹�����");
     command("recruit " + ob->query("id"));
}

string do_cancel()
{
        object me;
        int exp;

        me = this_player();
        exp = me->query("combat_exp");
        if(!me->query_condition("job_busy"))
              return "��û��������,������Ϲ����ʲ��?";
        if(!me->query_temp("quest") || me->query_temp("quest/family") != "��ɽ��")
              return "��û��������,������Ϲ����ʲ��?";
        me->clear_condition("job_busy");
        me->add("combat_exp",-(20+random(50)));
        if(exp>500000){
              me->add("combat_exp",-(10+random(40)));
              }
        me->apply_condition("job_busy",6+random(4));
        me->delete_temp("quest");
        return "��Ȼ��ɲ���Ҳû��ϵ,��ȥ�̿�������,�Ժ�����Ϊ���ǵĲ��ɴ�Ƴ���!";
}

string do_ask()
{
    object me, ob;      
    string type, t;
    mapping quest;
    
    me = this_player();
    ob = this_object();
    
    if(is_busy()) return "����æ���أ���ȵȡ�\n";
  
    if( me->query("combat_exp") < 50000 
     || me->query("shen") > 0)
            return RANK_D->query_respect(ob)+"�ҿ����ֽ�ɢ�����ж��ٻ����ټ��������������ܷ�������ȥ������أ�\n";
    
    if( me->query_temp("quest/id"))
            return "��������ȥ"+me->query_temp("quest/type")+me->query_temp("quest/name")+"������ô�������\n";
       
    if( me->query_condition("job_busy"))
            return "�ţ�����������˼�����ɴ�ƣ������š�\n"; 
     
    type = random(2)?"��":"ɱ";

    // get a random npc from TASK_D.
    if(!mapp(quest= TASK_D->get_quest(me, 0, type, "��ɽ��"))) 
            return "�ţ�����������˼�����ɴ�ƣ������š�\n"; 
            
    me->set_temp("quest", quest);
    me->apply_condition("job_busy", 25+random(30));    
    t = TASK_D->get_time(quest["time"]);   // get time limit.
    
    me->set_temp("songshan_job", 1);
    if(type == "ɱ"){
            command("grin");
            command("say �������ˣ��е��ӻر�"+quest["name"]+"���˶�����������֮�����������ô������");
            return "�ٺ٣�����"+quest["place"]+CYN"һ������ȥ����ɱ�ˣ������"+t+CYN"֮ǰ��������ʬ��ϻ�����\n";
            }
    else{
            command("nod");
            command("say ���ˣ�"+quest["name"]+"���ҽ��鲻���������������������֮�¼�ֱ���練�ơ�");
            return "��ʹ�����ȥ"+quest["place"]+CYN"�������������"+t+CYN"֮ǰ�ϻ�����\n";    
            }   
}

int accept_object(object who, object ob,object me)
{
       int type;
       me=this_object();
       
       // check job.
       
       if( who->query_temp("quest/family") != "��ɽ��")
                    return 0;
                        
       type = TASK_D->is_target(ob, who);
       switch (type){
            case 0: command("say ���ø�"+ob->name()+"���Ҹ��");
                    return 0;
            case -1:command("say Ү���������㲻ȥ����ɱ�˶���ȥ�ˣ�������");
                    return 0;
            case -2:command("say �ٺ٣�˭����ȥ��ɱ���ˣ���ֱ�Ǹ�����ɽ��Ĩ�ڣ�");
                    who->apply_condition("job_busy", 40);
                    return 0;
            case -3:command("say �ţ���ô�òŰ��꣬���ʲôȥ�ˣ����ҹ�һ��ȥ��");
                    who->apply_condition("job_busy", 30);
                    return 0;
            case -4:command("say Ŷ�����Ǹ�ͬ��ͬ�Ե��ˣ�������ù�ɣ�");
                    return 0;
            default:command("haha");
                    command("say �ã��ã�����²����ǿ�����ӡ�");
                    message_vision("\n$N��$n����һЩ��ѧ�ϵ����ѣ�$n������˼�ص���ͷ��\n",me, who);
                    // give rewards.
                    TASK_D->give_reward(who, who->query_temp("quest"), -1);
                    
                    who->add("songshan_points", 1);
        tell_object(who,HIW"/n�ã���Ϊ��������"+chinese_number(who->query("songshan_points"))+"�ι�����\n"NOR);
                    call_out("destroy", 1, ob);
                    return 1;
            }
      return 1;
}

void destroy(object ob)
{
        destruct(ob);
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && !is_busy()
           && ob->query_temp("quest/family") == "��ɽ��"
           && ob->query_temp("quest/type") == "��") {
                remove_call_out("greeting");
                call_out("greeting", 3, ob);
        }
}

void greeting(object me)
{
        object target, ob;
        mapping quest;
        
        if( !me || environment(me) != environment() || !living(me)) return;
        
        if (!mapp(quest = me->query_temp("quest")) || quest["type"] != "��"
        || !stringp(quest["id"])) return;
        
        command("nod "+me->query("id"));
        
        ob = this_object();
        
        if(objectp(target=present(quest["id"], environment(me)))
          && target->query_temp("songshan_job") == me
          && living(target)){
                ob->start_busy(2);
                target->set_leader(0);
                command("haha");
                command("touch "+target->query("id"));
                command("say "+target->name()+"����������ɽ���ֶ���һ����������������");
                
                /*
                if (quest["time"] < TIME_TICK ) {
                        command("say �ţ�"+me->name()+CYN"����ô�òŰ��꣬���ʲôȥ�ˣ����ҹ�һ��ȥ��");
                        me->delete_temp("quest");
                        me->set_temp("quest/last_id", quest["last_id"]);
                        me->apply_condition("job_busy", 30);
                        call_out("done", 3, target, me, quest, -1);
                }
                */
                call_out("done", 3, target, me, quest, 1);
                return;
        }
}

void done(object target, object me, mapping quest, int i)
{    
        if(me && i >= 0){
                if(target){          
                        message_vision("\n$N��ͷ����"+me->name()+"�����޲���������ָ�������У��͵��ǳ����ļ�����ɣ�\n", target, me);
                        tell_object(me,GRN+target->name()+"����Ķ�������˵����"+(random(2)?"ѩ��":"��ң")+"�������ǡ�"
                                +random(10)+random(10)+random(10)+random(10)+random(10)+"��\n" NOR);
                        tell_room( environment(me), target->name() + "��" + me->name()+ "����С����˵��Щ����\n", ({ me, target }) );
            // give rewards.
                        TASK_D->give_reward(me, me->query_temp("quest"), -1, ABS(me->query("songshan_points")/25));
            
                        me->add("songshan_points", 1);
        tell_object(me,HIW"/n�ã���Ϊ��������"+chinese_number(me->query("songshan_points"))+"�ι�����\n"NOR);
                        tell_room(environment(target), target->query("name")+"��Ц��������֪�͵��Ӵ����µ��᷿��Ϣȥ�ˡ�\n", ({target}));
                        if(!target->return_home()){
                                target->delete_temp("songshan_job");
                                target->delete_temp("last_lost_to");
                                target->clear_condition();
                                target->set("chat_chance", target->query("chat_c"));
                                if(!target->query_temp("location"))
                                        target->delete("location");
                                target->set_leader(0);
                                target->reincarnate();
                        }
                        
                        else destruct(target);
                }
        }
        
        else if(target){ 
                tell_room(environment(target), target->query("name")+"��Ц��������֪�͵��Ӵ����µ��᷿��Ϣȥ�ˡ�\n", ({target}));   
                destruct(target);
        }
                    
}
