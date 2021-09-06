#include <ansi.h>
inherit NPC;

string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��", "��","��" }); 
string *name_words = ({ "˳","��","��","��","��","��","��","��","־","��", "Т","��","��","��","��",
"��","��","ʢ","ʤ","��","��","��","ͬ","��", "��","��","��","¡","��","��","��","��","��" });
string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"}); 
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *rnd_say =({
"���������µ��ӣ�����˭��", 
"Ϊʲ���Һ���û�����㣿", 
"�ܸ���һЩǮ��", 
"�㲻���ң�", 
"�ɲ����Ը����������гԺȣ�", 
"hi", "hello", "hmm", "wa...",
"waley", "wait...", "hohoho", "hehe",
"ah..", 
});

varargs void drool(string msg, string who);
void create() 
{
        string name, id;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
        if( random(10) > 2 ) 
                name += name_words[random(sizeof(name_words))];
        id = rnd_id[random(sizeof(rnd_id))]; 
        if( random(10) > 4 ) 
                id += rnd_id[random(sizeof(rnd_id))]; 
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
        set_name(name, ({ id, "drooler"
}) ); 
        set("gender", "����"); 
        set("age", 14 + random(10));
        set("attitude", "friendly");
 	 set("shen_type", 1);
	 set("fight_times", 0);
        set("combat_exp", 50000 + random(5000));
        
        set_skill("sword",  50);
        set_skill("dodge",  50);
        set_skill("force",  50);
        set_skill("parry",  50);
        set_skill("tianmo-jian", 50);
        set_skill("tianmo-gong", 50);
        set_skill("ding-dodge",50);

	map_skill("force", "tianmo-gong");
	map_skill("parry", "tianmo-jian");
	map_skill("sword", "tianmo-jian");
       	map_skill("dodge", "ding-dodge");
	create_family("�������", 10, "����");
 
        set("env/wimpy", 100); 
        set("chat_chance", 30); 
        set("chat_msg", ({ 
                (: command, "get all" :), 
                (: command, "wear all" :), 
                (: command, "wield all" :), 
                (: drool :), (: drool :), 
                (: drool :), (: drool :), 
                (: drool :), (: random_move :),
}) ); 

        setup(); 
        if( clonep() ) 
                CHANNEL_D->register_relay_channel("chat");
	carry_object("/d/city/npc/obj/changjian")->wield();
	carry_object("/d/city/npc/obj/cloth")->wear();
 
}

int add_phrase(string who, string msg) 
{ 
        msg = replace_string(msg, "?", ""); 
        msg = replace_string(msg, "��", ""); 
        msg = replace_string(msg, "��", ""); 
        msg = replace_string(msg, "!", ""); 
        msg = replace_string(msg, "��", ""); 
        msg = replace_string(msg, "��", ""); 
        msg = replace_string(msg, "��", ""); 
        msg = replace_string(msg, "Ү", ""); 
        msg = replace_string(msg, "��", "");

        if( msg!="" ) { 
                add("memory/" + who, ({ msg })); 
                return 1; 
        } 
        else return 0; 
}

string make_reply() { }

void relay_channel(object ob, string channel,
string msg) 
{ 
        string who;
        if( !userp(ob) || (channel != "chat"))
        return; 
        who = ob->query("name");

// Don't process our own speech. 
        if( ob==this_object() ) return;
        if( add_phrase(who, msg) && random(10)> 4 ) 
        drool(msg, ob->query("name")); 
}

void relay_say(object ob, string msg) 
{ 
        string who;
        if( !userp(ob) ) return; 
        who = ob->query("name");

// Don't process our own speech. 
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10)
> 4 ) 
                drool(msg, ob->query("name")); 
}

void relay_emote(object ob, string verb) 
{ 
        if( !userp(ob) ) return;

        switch(verb) { 
                case "kick": 
                if( random(10)<5 ) { 
                                command("say Ϊʲ���Ͽ��ң�"); 
                                break; 
                        } 
                default: 
                        if( random(10)<5 ) 
                                command(verb + " " + ob->query("id"));
                        else drool(); 
        } 
}

varargs void drool(string msg, string who) 
{ 
        mapping mem; 
        string *ob;

        mem = query("memory"); 
        if( !mapp(mem) ) return;

        if( !msg || !who) { 
                ob = keys(mem); 
                who = ob[random(sizeof(ob))]; 
                msg = mem[who][random(sizeof(mem[who]))]; 
        }

        if( (strsrch(msg, "Ϊʲ��") >=
0) ) { 
                if( sscanf(msg, "%*sΪʲ��%s", msg)==2 ) 
                        msg = "Ϊʲ��" + msg; 
                        switch(random(8)) { 
                                case 0: 
                                        command("say " + who + "��������������");     break;
                                case 1: 
                                        command("say ���" + msg + " ... ");break; 
                                case 2: 
                                        command("say �� ... "); drool(); break; 
                                case 3: 
                                        command("say ��������� ...."); break; 
                                case 4: 
                                        command("say " + who + "��֪���������Ĵ𰸶���������Ҫ��");break; 
                                case 5: 
                                        command("say " + msg + "��"); break;
                                case 6: 
                                        command("say " + who + "���ܲ���˵���һ�㣿");break; 
                                case 7: 
                                        command("say " + who + "���Ҳ������ʵ�����");break; 
                        } 
                } 
                else 
                if( (strsrch(msg, "��") >= 0) || (strsrch(msg, "��")>= 0) 
                || (strsrch(msg, "drooler") >= 0) || (strsrch(msg,"Drooler") >= 0)) { 
                        if( sscanf(msg, "%*s��%s", msg) == 2 ) 
                                msg = "��" + msg; msg = replace_string(msg, "��","��"); 
                        msg = replace_string(msg, "��", "��");
                        switch(random(10)) { 
                                case 0: 
                                        command("say " + who + "������˵"+ msg + "��"); break; 
                                case 1: 
                                        command("say ��ȷ��" + msg + "��");break; 
                                case 2: 
                                        command("say " + msg + "������ʲ���ϵ��");break;
                                case 3: 
                                        command("say �� ... " + who + "˵�ú�");break; 
                                case 4: 
                                        command("say " + who + "��Ϊʲ���"+ msg + "��������Ȥ��"); break; 
                                case 5: 
                                        command("say Ϊʲ������Ϊ" + msg + "��");break; 
                                case 6: 
                                        command("say ���������"); drool(); break;
                                case 7: 
                                        command("say �Ź�"); break; 
                                case 8: 
                                        command("say ��һ���ɣ�"); break; 
                                case 9: 
                                        command("say ��������� ...."); break; 
                        } 
                } 
                else 
                if( (strsrch(msg, "��") >= 0)) { 
                        if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��"+ msg; 
                        msg = replace_string(msg, "��", "��");
                        msg = replace_string(msg, "?", ""); 
                        switch(random(8)) { 
                                case 0: 
                                        command("say ����˵" + msg + "��");break; 
                                case 1: 
                                        command("say ��ģ�" + msg + "��");break; 
                                case 2: 
                                        command("say ���" + msg + "�����ܰ���ʲ��æ��");break; 
                                case 3: 
                                        command("hmm"); break; 
                                case 4: 
                                        command("say ����Ϊ" + msg + "��");break; 
                                case 5: 
                                        command("say ����ͬ��"); break; 
                                case 6: 
                                        command("say ��˵�ġ�" + msg + "���Ҳ��ܹ�ͬ");break; 
                                case 7: 
                                        command("say �йء�" + msg + "���Ļ��⵽��Ϊֹ����");break; 
                        } 
                } 
                else { 
                        switch(random(20)) { 
                                case 0: 
                                        command("say Ϊʲ��˵" + msg + "?");break; 
                                case 1: 
                                        command("say ��" + msg + "����ʲ����˼��");break; 
                                case 2: 
                                        command("say " + msg + "��"); break;
                                case 3: 
                                        command("grin"); break; 
                                case 4: 
                                        command("smile"); break; 
                                case 5: 
                                        command("?"); break; 
                                case 6: 
                                        command("say ...."); break; 
                                case 7: 
                                        command("hmm"); break; 
                                case 8: 
                                        command("say " + rnd_say[random(sizeof(rnd_say))]);break; 
                                case 9: 
                                        command("say ������֪��" + msg + "?");break;
                                case 10: 
                                        command("say �ո�" + who + "����˵�ˣ�"+ msg); break; 
                                case 11: 
                                        command("say �ҵ�Ȼ֪����" + msg); break;
                                case 12:
                                        command("say Ȼ���أ�"); break; 
                                case 13:
                                        command("say �����"); break; 
                                case 14:
                                        command("say �Ҳ�������Ϊ��"); break;
                                default: break; 
                } 
        } 
}

void reset() 
{ 
        delete("memory"); 
}

int accept_object() { return 1; } 
