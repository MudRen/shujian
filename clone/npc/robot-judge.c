//  robot-judge.c
//  By Jpei  Aug 1997
//  Add cleaner By Bbb
//  Change question format By Look
inherit NPC;
#include <ansi.h>
#include <mudlib.h>

int do_answer(string arg);
int ask_judge();
int ask_rejudge();

string *key=({
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������",
"����������������������������������������������������������������������������"
});

string ans="";
string str="";

varargs void drool(string msg, string who, object ob, string channel);

string *fuck = ({
      "fuck","FUCK","ƨ��","������","������","�����",
        "��ƨ","����","����","ɵB","ɵb","ɵX","ɵx","tmd","tnnd",
      "���","��Ѿ","Ѿͦ","�����","ȥ����","������","��Ů",
        "X����","����","����","ɵ��","����"
        });

varargs void alldrool(string msg, string who, object ob);

string *allfuck = ({
      "ƨ","��","��","��","��","��","үү",
        "��","��","��","ɵ","Ѿ","��","����","����",
        "����","�׳�","��","��","�","cao","Ѩ","ֵǮ",
        "С��","��","����","��","��","��","��","��",
        "shit","SHIT","��","��","����","����","��","ĸ��"
        });

//��������ų���������һ�� emote ȫ��¼�ˣ��д�����
string *except = ({
      "��Ц","����","����","���","����","����","ƨ��","�ɻ�","�ɹ�",
"ɵ��","�ɲ�","��","��Ц","Ѩ��","����","ɵЦ","�޵�����","��޳ɵ","˿����",
"��ȥ�ĵ���","����","���ֶ�","ɵڶ","����","ɵ��","����","�ô���","���̵���"
        });

void create()
{
        set_name("�����˷���", ({ "jiqiren faguan", "jiqiren", "faguan", "robot judge", "robot", "judge" }));
        set("shen_type", 0);

        set("gender", "����");
        set("age", 20);
        set("long", "����һ��ר�����л����˵ķ��١�\n");
        set_skill("dodge", 1000);
        set("max_qi", 10000);
        set("qi", 10000);
        set("max_jing", 10000);
        set("jing", 10000);

        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("inquiry", ([
                "name": "�㻹�����й��򰡣�",
                "rumors": "��˵���Ǹ������ˣ��ٺ٣�����ؿ�����������ѽ��",
                "here": "�����Ƿ�ͥ��û�²�׼������",
                "����": (: ask_judge :),
                "��Ѷ": (: ask_judge :),
                "����": (: ask_rejudge :),
        ]) );

        setup();

        if( clonep() ){
                CHANNEL_D->register_relay_channel("chat");
                CHANNEL_D->register_relay_channel("rumor");
                CHANNEL_D->register_relay_channel("party");             
		CHANNEL_D->register_relay_channel("sj");
        }


}

void init()
{
        object ob = this_player();
        add_action("do_answer", "answer");
        add_action("do_answer", "huida");
        ob->set_temp("robot_judge", -1);
        if (!wiz_level(ob) && !ob->is_busy()) ob->start_busy(15);
        call_out("ok", 30, ob);
}

void ok(object ob)
{
        if (!ob || environment(ob) != environment()) return;
        ob->delete_temp("robot_judge");
        if (userp(ob) && !wiz_level(ob)) {
            command("say " + ob->name(1) + "���ڽ�����Ѷ���κ�ʱ��Կ���Ҫ�����С�");
            }
        tell_object(ob, "����̧��ͷ���˿��㣬ʾ������Կ�ʼ�ˡ�\n");
        ob->apply_condition("judgement",10);
}

void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("$N��ɥ�ط��ֻ����˷��ٸ����������ս����\n", ob);
}

void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        say("�����˷�����Ц��˵�������޵в����棡\n");
        command("hehe");
}

void die()
{
        unconcious();
}

int do_answer(string arg)
{
        object ob = this_player();
	
        if (!arg) return 0;
        if (ob->query_temp("robot_judge") != 1) return 0;
        ans = ob->query_temp("answer");
        if (arg==ans) {
                tell_object(ob, "�����˷��ٵ��˵�ͷ��˵����OK����������ˡ�\n");
                command("say ��ͥ�������У�" + ob->name(1) + "���ػ�����һ������ط�֤�ݲ��㣬��" + ob->name(1) + "�����ͥ�ͷš�");
                ob->delete_temp("robot_judge");
                ob->delete_temp("answer");
		ob->clear_condition("robot");
		ob->set_temp("robottest", uptime());
                if (ob->query("catch_robot_place") 
                && ob->query("catch_robot_place") != base_name(environment()) 
                && ob->query("catch_robot_place") != USER_OB ) 
                	ob->move(ob->query("catch_robot_place"));
                else if (ob->query("enter_wuguan")) ob->move("/d/wuguan/dayuan");
                else ob->move("/d/city/chmiao");
        }
        else {
                tell_object(ob, "�����˷���̾�˿���������ô�򵥶��𲻶ԣ�����һ�������ˣ�\n");
                command("say ��ͥ�������У�" + ob->name(1) + "��" + ob->query("gender") + "��" + chinese_number(ob->query("age")) + "�꣬����������������ʮ���������������������в����������ߡ�");
                ob->set_temp("robot_judge", 2);
        }
        return 1;
}

void test_robot(object ob)
{
        int temp, line, ltemp, c, cl, len;
        ans="";
        str="";
        tell_object(ob, "�����˷������������ӣ�˵���������������п�ʼ����ش�һ��С���⡣��\n");
        ob->set_temp("robot_judge", 1);
        temp = len = random(3) + 3;
        while (temp--) {
            ans += "0";
            ans[<1] += random(10);
        }
        line = random(5)*6;
        for (ltemp = line; ltemp < line+6; ltemp++) {
            for (temp = 0; temp < len; temp++) {
                c = ans[temp] - '0';
                if (c != 1) cl = 7;
                else cl = 3;
                if (c > 1) c = c * 8 - 4;
                else c *= 8;
                cl += c;
                str += key[ltemp][c..cl];
            }
            str += "\n";
        }
        ob->set_temp("answer",ans);
        tell_object(ob, "����answer����ش���������������ʲô��\n");
        tell_object(ob, str);
}

int ask_judge()
{
        object ob = this_player();
        int temp;
        if (temp = ob->query_temp("robot_judge")) {
                if (temp < 0) {
                        write("���һ�ᣬ�������ڿ�������ϡ�\n");
                        return 1;
                }
                if (temp > 1) {
                        write("���Ѿ������й��ˣ����в��������ߣ�\n");
                        return 1;
                }
                else {
                        write("�����������У�\n");
                        return 1;
                }
        }
        command("say ��ͥ��������" + ob->name(1) + "����Ϊ������һ����");
        test_robot(ob);
        return 1;
}

int ask_rejudge()
{
        object ob = this_player();
        int temp;
        if (temp = ob->query_temp("robot_judge") < 2) {
                if (temp == 1) {
                        write("�����������У�\n");
                        return 1;
                }
                else {
                        write("�㻹û�����й�������ʲô����\n");
                        return 1;
                }
        }
        command("say ��ͥ��������" + ob->name(1) + "����Ϊ������һ�������߰���");
        test_robot(ob);
        return 1;
}

void relay_channel(object ob, string channel, string msg)
{
        string who;
        if( !userp(ob) ) return;
        if( ob==this_object() ) return;
        who = ob->query("name");
        drool(msg, who, ob, channel);
//	alldrool(msg,who,ob);
}

//��¼�໰���ر�Ƶ��
varargs void drool(string msg, string who, object obj, string channel)
{
        mapping mem;
        string *ob;
        object me = this_player();
        int i, flag = 0;

        mem = query("memory");
        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
	i = strlen(msg);
	while (i--) {
		if (msg[i] >= 'A' && msg[i] <='Z') {msg[i]+=32; continue;}
		if (msg[i] >= 'a' && msg[i] <='z') continue;
		if (msg[i] > 128) continue;
		msg = msg[0..i-1] + msg[i+1..<1];
	}
        for(i=0;i<sizeof(fuck);i++){
                if (strsrch(msg, fuck[i]) >= 0) flag=1;
        }
        if( flag )
        {       if (wiz_level(me)<3){
                message("shout", HIC "��ͨ�桿" + who + "�� " + channel + " Ƶ�������к��в����Դʣ���ʱ�ر����н�̸Ƶ��������¼�ڰ����Ⱥ���\n" NOR,users());
                log_file("FUCK",
			sprintf("%s(%s) %s %s\n",
                		me->query("name"),me->query("id"), channel, msg
			), me
		);
		me->apply_condition("vote_chblk", 40);
                obj->set("chblk_on", 1);
                obj->set("chblk_party", 1);
		obj->set("chblk_sj", 1);
                }
        }
        return;
}

//��¼ȫ�������ɵĻ��������ر�Ƶ����������ʦ���� ��Ȼ��Ǻܶ࣬�ܱ� log ȫ���õ�
varargs void alldrool(string msg, string who, object obj)
{
        mapping mem;
        string *ob;
        object me = this_player();
        int i, j,flag = 0;
        mem = query("memory");
        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        for(i=0;i<sizeof(allfuck);i++)
        for(j=0;j<sizeof(except);j++){
                if (strsrch(msg, allfuck[i]) >= 0 )     flag=1;
                if (strsrch(msg, except[j]) >= 0) flag =0;
	}
        if( flag )
        {
                write_file( "/log/ALLFUCK", sprintf("%s %s(%s)˵��%s\n", ctime(time())[4..19],
                me->query("name"),me->query("id"),msg));
        }
}
