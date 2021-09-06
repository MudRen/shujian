//ʥ������ pig.c
//Created by campsun 2003.12.14

inherit NPC;

#include "pig.h"
#include <ansi.h>

                     
mapping map_menpai = (["wd" : wd_desc,
                        "hs" : hs_desc,
                        "ss" : ss_desc,
                        "gm" : gm_desc,
                        "gb" : gb_desc,
                        "tz" : tz_desc,
                        "dls" : dls_desc,
                        "mr" : mr_desc,
                        "sld" : sld_desc,
                        "xx" : xx_desc,
                        "em" : em_desc,
                        "mj" : mj_desc,
                        "thd" : thd_desc,
                        "tls" : tls_desc,
                        "sl" :sl_desc
                        ]);

mapping pig_desc;
string pig_party;


string gGetRndColor()
{
        string* color = ({RED,GRN,YEL,BLU,MAG,CYN,HIR,HIG,HIY,HIB,HIM,HIC,HIW});
        return color[random(sizeof(color))];
}
                 
void create ()
{
        set_name("pig",({"pig"}));

        set("shen_type", 1);
         set("gender", "Ů��");
        set("age", random(10)+10);
        set("attitude","heroism");
        
        set("str", 20);
        set("con", 20);
        set("int", 20);
        set("dex", 20);
        set("kar", 20);
        set("per", random(40));
        set("max_jing",3000);
        set("max_qi",3000);
        set("cloned",0);
        set("gong",1);
        set("answer",0);
        set("getfood",0);
        set("party","tls");
        set("quest_passed",0);
        set("combat_exp",50000000);
        setup();
}    

void init()
{

        string strTemp;
        object ob = this_object();
        
        
        add_action("do_gong","gong");
        add_action("do_answer","answer");
        if (!ob->query("cloned")){
                //pig_party = str_menpai[random(sizeof(str_menpai))];
                pig_party = ob->query("party");
                pig_desc = map_menpai[pig_party];
                
                set_name(gGetRndColor() + pig_desc["nickname"]  + "��"NOR,({pig_party + " piggy","piggy","pig"}));
                set("long",gGetRndColor() + "����һֻ�ʷ����ֿɰ��Ĵ���\n" + pig_desc["desc"] + "\n�ƺ�Ҫ" +YEL "����Gong��"NOR + "�����п���������"NOR);
                set("cloned",1);
                set("chat_chance", 5);
                call_out("do_over",6000);
        }
        strTemp = query("name") + gGetRndColor() +"�����﷢�����ߺ����󡱵�������\n"NOR;
        strTemp = strTemp + query("name") +gGetRndColor() + "�����ţ�������ѽ���㵹�ǹ���ѽ��WIZ���Ѿ��������ˣ���Ҳ����ѽ~~~~����\n"NOR;
        strTemp = strTemp + query("name") +gGetRndColor() + "�����ţ���" + pig_desc["say_desc"]+"����\n"NOR;
        set("chat_msg", ({strTemp}) );
}
int do_gong(string arg)
{
        object me = this_player();
        object ob = this_object();
        int i,improve;
        
        if (!ob->query("gong"))
                return 0;
        
        if (me->query("family/family_name")!=pig_desc["party"])
        {
                tell_object(me,HIG"����Ϊ��ͷ���Ϳ��Թ�����ô���������д�������\n"NOR);
                return 1;
        }
        message_vision(HIG"$N���Լ��ı��Ӵ���ȥ��$n"+HIG+"�������š�����ֻ�������ô����ô��ѽ����\n"NOR,me ,ob);
        
        if (random(me->query("kar"))<=0)
        {
                ob->set("gong",0);
                ob->set("answer",1);
                tell_object(me,HIW"����ΪŬ������������Ϊ�õ���������\n"NOR);
                improve = random(10) + 10;
                me->add("max_neili",improve);
                log_file("quest/sdgift",sprintf("%s %s(%s)Ŭ����%s��������%s�㡣\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
                message_vision("$N"+HIG+"��$n���˲����ϵĺ��������ú�����ɣ���\n"NOR,ob ,me);
                switch (ob->query("quest_passed"))
                {
                case 0: 
                        message_vision("$N"+HIG+"˵�����������ǹ�����ô���࣬�����������ǣ����ǻش�"+RED+"answer"+NOR+HIG"�������ҾͶ���һ�±�ʾ�ҵ�ο�ʡ���\n"NOR,ob);
                        message_vision("$N"+HIG+"˵������"+gGetRndColor() +pig_desc["question"] +HIG+"��\n"NOR,ob );
                break;
                case 1:
                        i = random(sizeof(question2));
                        set("question2_answer",question2[i]["answer"]);
                        message_vision("$N"+HIG+"˵�����������ǹ�����ô���࣬�����������ǣ����ǻش�"+RED+"answer"+NOR+HIG"�������ҾͶ���һ�±�ʾ�ҵ�ο�ʡ���\n"NOR,ob);
                        message_vision("$N"+HIG+"˵������"+gGetRndColor() +question2[i]["question"] +HIG+"��\n"NOR,ob );
                break;
                case 2:
                        i = random(sizeof(food));
                        set("food_id",food[i]["id"]);
                        set("food_name",food[i]["name"]);
                        message_vision("$N"+HIG+"˵�����������ǹ�����ô���࣬�Ҿʹ󷢴ȱ��������ɡ���\n"NOR,ob );
                        message_vision("$N"+HIG+"�����������������������飬ʵ������ҪӪ��������\n"NOR,ob );
                        message_vision("$N"+HIG+"˵����������ʲô����ֵģ�������ô����ȻҪ���Եģ��Ҳ�����������ʹ�죬����ȥŪ����"+gGetRndColor()+ob->query("food_name")+HIG"�������ɣ���\n"NOR,ob );
                        ob->set("getfood",1);
                        ob->set("gong",0);
                        ob->set("answer",0);
                break;
                }
                
        }
        if(!wizardp(me)) me->start_busy(2);
        me->add_temp("havegong",1);
        return 1;
}
int do_answer(string arg)
{
        object me = this_player();
        object ob = this_object();
        int improve;
        
        if (!ob->query("answer"))
                return 0;
        switch (ob->query("quest_passed"))
        {
        case 0:
                if (arg != pig_desc["answer"])
                {
                        message_vision("$N"+gGetRndColor()+"��$n�ٺ�һЦ������ҿ��������Դ�ѽ����������\n"NOR,ob ,me);
                        return 1;
                }
                ob->set("quest_passed",1);
        break;
        case 1:
                if (arg != ob->query("question2_answer"))
                {
                        message_vision("$N"+gGetRndColor()+"��$n�ٺ�һЦ������ҿ��������Դ�ѽ����������\n"NOR,ob ,me);
                        return 1;
                }
                ob->set("quest_passed",2);
        break;  
        }
        tell_object(me,HIW"����Ϊ����ش���ȷ�����һЩǱ�ܽ�����\n"NOR);
        improve = random(100) + 100;
        me->add("potential",improve);
        log_file("quest/sdgift",sprintf("%s %s(%s)�����%s��������� ����Ǳ��%s�㡣\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));        
        message_vision("$N"+gGetRndColor() + "������$n��ͷ�����������������\n"NOR,ob ,me);
        message_vision("$N"+gGetRndColor() + "���ŷ�����$n�������������ʲô�ѽ���ش����ô�򵥵������ָ�������������������㡭����\n"NOR,ob ,me);
        ob->set("answer",0);    
        ob->set("gong",1);      
        return 1;               
                

}
int accept_object(object who, object ob)
{
        object me,ofood,egg;
        int i;
        int improve;
        ofood = ob;
        ob = this_object();
        me = this_player();
        
        if (!ob->query("getfood")) return 0;
        
        if (strip(ofood->query("name"))!=strip(ob->query("food_name"))) return 0;
        //if (ofood->query("id")!=ob->query("food_id")) return 0;
        
        message_vision("$N"+gGetRndColor() + "���˵���������������$nʹ�����飺�������ڳԵ���ô��ζ��$n������\n"NOR,ob ,ofood);
    message_vision("$N"+gGetRndColor() + "��$n�Եľ��⡣\n"NOR,ob ,ofood);
        message_vision("$N"+gGetRndColor() + "��$nʹ��һ���ۣ�$n���е�С¹������\n"NOR,ob ,me);
        tell_object(me,HIW"����Ϊ�����ҵ���ʳ����һЩ���齱����\n"NOR);
        improve = random(500) + 500;
        me->add("combat_exp",improve);
        log_file("quest/sdgift",sprintf("%s %s(%s)ι%s ����ʵս����%s�㡣\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),this_object()->name(),chinese_number(improve)));
        
        call_out("destroying", 1, ofood);
        if (random(10)>2)
        {
                i = random(sizeof(food));
                set("food_id",food[i]["id"]);
                set("food_name",food[i]["name"]);
                ob->set("food",1);
                message_vision("$N"+HIG+"�����Լ��Ķ��ӣ��������һ�û�Ա��ء���\n"NOR,ob );
                message_vision("$N"+HIG+"˵������������ȥŪ����"+gGetRndColor()+ob->query("food_name")+HIG"�������ɣ���\n"NOR,ob );
                return 1;               
        }
        else
        {
                message_vision("$N"HIG"�����Լ��Ķ��ӣ����Ե��汥������͸����������ɣ���\n"NOR,ob );
                command("chat " + me->query("name") + HIY"���齣ȫ�幤����Աף��ʥ�����֣�����"NOR);
                message_vision("$N"+HIG+"��$nһ�š�����ʥ����������\n"NOR,ob,me );
                egg = new("/d/city/npc/obj/egg");
                egg->move(me);
                log_file("quest/sdgift",sprintf("%s %s(%s)�õ��ˡ�����ʥ������\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id")),));
                call_out("do_over",10);
                return 1;
        }
}
void do_over()
{
        object ob = this_object();
        remove_call_out("do_over");
        message_vision("$N"+HIG+"˵�������Ա��ˣ��Ҹ�ȥ˯һ���ˡ���\n"NOR,ob );
        message_vision("$N"+HIG+"һ��һ�ε��뿪�ˡ�\n"NOR,ob );
        destruct(ob);
        return; 
}
void die()
{
        unconcious();
}

void unconcious()
{
	say(this_object()->name()+"��һ��: ��������������ô�����ڼ����˰�\n");
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        clear_conditions_by_type("poison");
}

void destroying(object ob)
{     
       if (!ob) return;
       if (userp(ob)) command("drop "+ob->parse_command_id_list()[0]);
        else destruct(ob);
}