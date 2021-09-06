//      File    :  /adm/daemons/explored.c
//
inherit F_DBASE;

#define SRCH_DIR "/d/"
#include <ansi.h>
#include <explore.h>
#include <get_place.h>
#include <dbase.h>
int explore_level = EXPLORE_LEVEL;
int Check_Illgeal_Target(object target);
int Start_Job(object me, object ob);
int check(object ob);

void create()
{
        set("channel_id", "��������");
        CHANNEL_D->do_channel( this_object(), "sys", "̽��ϵͳ�Ѿ�������\n");
//      Start_Job();
}

// ����ɱ�ּ���ˮƽ
void Copy_Skill(object me, object ob)
{
        return;
}

mapping *corpse_des = ({
([      "shen"      :     "-1",
        "content"   :     ({
        ([
                 "name" : "�ڷ�˫ɷ",
                 "des"   : "\n����ϸ������ʬ�װ��죬��Ȼ����ʬ���ͷ­�Ϻ�Ȼ�����Ѫ����\n",
                 "tar" : "������һ����Ī���Ǻڷ�˫ɷ��Ϊ�����Ͻ���������",
        ]),
        ([
                 "name" : "��Զɽ",
                 "des"   : "\n����ϸ������ʬ�װ��죬ֻ�������ϼ��⽩Ӳ����������ȥ�������ƣ������������⣬��̽����Ϣ������������ʱ�����ؼ������һ�������֣��߹���ϣ��������ѡ�����Ȼ��������ͻ�����֣���ʱ������\n",
                 "tar"  : "������һ����Ī���ǽ����Ƶ�������������һ���������֮������",
        ]),}),
]),
([      "shen"      :     "1",
        "content"   :     ({
        ([
                "name"  : "�԰�ɽ",
                "des"   : "\n����ϸ������ʬ�װ��죬���������������ʱ��,������ǰ���������,���Ʊ����������һ��\n",
                "tar"   : "������һ����Ī���Ǻպ��������䵱������Ϊ����",
        ]),
        ([
                "name"  : "������",
                "des"   : "\n����ϸ������ʬ�װ��죬�������Ϻ���㣬��ɫ�԰׵ú��ˡ����Ǳ�һ�������ڹ���Ϊ\n",
                "tar"   : "������һ����Ī�����������µ���ϼ�񹦵Ļ�Ԫ�޼���������",
        ]),
        }),
]),
});

int Check_Npc(object obj)
{
        int i;
        string name;
        string *banned_name= ({ "С����","ľ��","���","���޳�","������","ƽ��",
                           "���ݹ�ͯ","���޳�","��������","��ʦ","���ϰ�",
                           "����","�����ϰ�","����Ⱥ","��Զ��","����ѧʿ"});

        name = obj->query("name");

        if( member_array(name, banned_name)!=-1 ) {
                return 0;
        }

 	write(sprintf("%d ",clonep(obj)));
        if( !obj->is_character()
        ||  userp(obj)
        ||  obj->query("race")!="����" )
                return 0;

	return 1;
}

int Check_Illgeal_Target(object target)
{
        // ��ֹ���������NAME��ͬ��
        if(target->query("name") == this_object()->query("last_target"))
                return 0;

        return 1;
}

string Check_Family(string npcfile)
{
        string family;
        family = npcfile->query("title");
        if(!family) family="";
        return family;
}

string Check_Family1(string npcfile)
{
        string family;
        family = npcfile->query("family/family_name");
        if(!family) family="";
        return family;
}

string Get_Npc()
{
        string family, times, npcfile;
        int i, size;
        object target;
        object *living;


        living=filter_array(livings(), (: Check_Npc :));
	write(sprintf("��NPC:%d ",sizeof(livings())));
        size=sizeof(living);
	write(sprintf("\n���˺�NPC:%d\n",size));
        i=random(size);

        while(1) {
                target=living[i];
                if( Check_Illgeal_Target(target)) {
                        npcfile=file_name(target);
                        printf("Npc:%s\n", npcfile);
                        return npcfile;
                }
                i++;
                if ( i >= size ) i=0;
                if ( i == size ) break;
        }

}

void get_corpse(string npc_file, string file_name, object me)
{

        int i, k, p;
        object *inv;
        object corpse, room, victim;

        if(!(victim = find_object(npc_file)))
             victim = load_object(npc_file);
        if(!(room = find_object(file_name)))
             room = load_object(file_name);
        corpse = new(EXPLORE_OB);
        corpse->move(file_name);
//      corpse->set("dead_message","");
//      corpse->die();        
        corpse->set_name( victim->name(1) + "��ʬ��", ({ "corpse" }) );
        corpse->set("age", victim->query("age"));
        corpse->set("gender", victim->query("gender"));
        corpse->set("victim_name", victim->name(1));
        corpse->set("victim_id", victim->query("id"));
        corpse->set("victim_exp", victim->query("combat_exp"));
        corpse->set("victim_shen", victim->query("shen"));
        corpse->set_weight( victim->query_weight() );   
        corpse->set_max_encumbrance( victim->query_max_encumbrance() );
//      corpse->move(file_name);
        if( !wizardp(victim) ) {
                inv = all_inventory(victim);
                inv -= ({ 0 });
                i = sizeof(inv);
                while(i--) {
                        if( (string)inv[i]->query("equipped")=="worn" ) {
                                inv[i]->move(corpse);
                                if( !inv[i]->wear() ) inv[i]->move(environment(victim));
                        }
                        else inv[i]->move(corpse);
                }
        }
        corpse->set("long", victim->long(1)
                + "Ȼ����" + gender_pronoun(victim->query("gender")) 
                + "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");        
        
        

        if( (int)me->query("shen") < 0) k=0;
        if( (int)me->query("shen") > 0) k=1;
        p=sizeof(corpse_des[k]["content"]);
        p=random(p);
        corpse->set("corpse_des", corpse->query("long")+corpse_des[k]["content"][p]["des"]);
        
        return;
}

int Start_Job(object me, object ob)
{
        mapping my, tmp_my;
        string dir_name, file_name, chinese_name, npcfile, name, family;
        int exp, num;
        object shashou/*, corpse, room*/;
        object *living, target1, target2, objwhere;
        int i,j;
        string str;

        seteuid(getuid());

	//ȡ��һ��ϵͳ�ڵ�NPC

        living=filter_array(livings(), (: Check_Npc :));
	write(sprintf("��NPC:%d ",sizeof(livings())));
	write(sprintf("\n���˺�NPC:%d\n",sizeof(living)));
        i=random(sizeof(living));

        while(1) {
                target1=living[i];
                if( Check_Illgeal_Target(target1)) {
                        npcfile=file_name(target1);
                        printf("Npc:%s\n", npcfile);
                        break;
                }
                i++;
                if ( i >= sizeof(living) ) i=0;
                if ( i == sizeof(living) ) break;
        }
        
        
//        dir_name = Get_Dir();
//        file_name = Get_File(dir_name);
//        chinese_name = Chinese_Dir(dir_name);
	//ȡ��һ��ϵͳ�ڵĵص�               
	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (!j || j == sizeof(living) -1) continue;
		if(check(living[j]) ){
			target2 = living[j];
			objwhere = environment(target2);
			str = objwhere->query("short");
			if (!sizeof(objwhere->query("exits"))
			|| str == "��ɮ��"
			|| str == "ɮ��"
			|| str == HIR"������"NOR
			|| str == "��շ�ħȦ" ) continue;
			if( get_place(base_name(environment(target2))) != "" ) break;
		}
	}

	if( !target2 ){
		write("��ʱû��������Ҫ�������һ��������ɡ�");
		return 1;
	}
		
        family = Check_Family(npcfile);
        name = objwhere->query("short");
        if( explore_level > EXPLORE_LEVEL ) {
                remove_call_out("Start_Job");
                return 1;
        }
        write("�ص㣺"+base_name(objwhere)+"\n");
        get_corpse(npcfile, base_name(objwhere), me);
        this_object()->set("last_target", npcfile->query("name"));
        CHANNEL_D->do_channel( this_object(), "chat", sprintf(HIC"��˵ "+HIW + "��"+ HIY +"%s��%s%s" + HIW + "�� " + HIC + "ǰЩ������ " + HIW + "��%s��%s"+ HIW + "��"+ HIC + " ������������λӢ����̽�þ���������ʤ�м���"NOR, 
        get_place(base_name(environment(target1))),family,target1->query("name"),get_place(base_name(objwhere)),name));
//call_out("Start_Job", 150, this_object());
        return 1;

//      if( exp > 20000 ) {  // exp ���� 20k �Ϳ�����Job

              shashou = new("/d/city/npc/xiaoer"); // ����һ��ɱ��

// ��ʼ����shashou����ˮƽ
//              Copy_Skill(me, ob);
// ����������ͷ������ʦ�ļ���ˮƽ

              shashou->set("catch_user_id",me->query("id"));
              shashou->move(environment(me));

//      }

}

int set_explore(int level)
{
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        explore_level = level;
        return 1;
}

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("outdoors") == "���ش��"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/changle/") == 0
	 || strsrch(room_name, "/d/city/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
		return 0;
	return 1;
}
