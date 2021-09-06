// qqllyu.c ����������
// kxkxkx 2004��3��
// Modified by Ciwei@SJ

#include <ansi.h>
#include <command.h>

inherit ITEM;

private nomask int lingwu_hook(string arg);
private nomask void lingwu_hook_completion(object user,string str);

void create()
{
   set_name(HIG"����������"NOR, ({"qqllyu","qiqiaolinglong yu", "yu"}));
   set_weight(100);
   if(clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("long",
      	"��"HIG"һ������������ʯ\n"
      	"  ��Ϊ������������"NOR"��\n"
      	"\n"
      	"һ����������񣬰��������컯����֮�\n"
      	"�ƺ���������������"HIY"lingwu <����> with yu"NOR"����\n"
         );
      set("no_get", 1);
      set("no_steal", 1);
     set("no_give",1);
     set("no_drop",1);   
      set("flag","spec/cantu");
      set("desc","������������β������");
      set("credit",2500);
      set("degree",1);
   }
   setup();
}

void init()
{
   add_action("lingwu_hook", "lingwu ", 2);
}

private nomask int lingwu_hook(string arg)
{
   string* l_skills = ({ // �Ӹ���Ŀ�������
      "duanzao",
      "zhizao",
      "nongsang",
      "caikuang"
   });
	object user, room;
	string str,id;
	int lvl;

   user = this_user();
	if(!arg || sscanf(arg, "%s with %s", str,id) != 2 )
		return notify_fail("��ʽ�� lingwu <����> with qiqiaolinglong yu\n");
		//�������return 1 ���޷�����yu ȥ��ĵط�lingwu so fixed it ciwei@SJ
	if(!objectp(present(id, user)) || present(id, user)!=this_object() ) return 0;	
	if(!str){
		tell_object(user,"��ʽ�� lingwu <����> with qiqiaolinglong yu\n");
		tell_object(user,"��Ҫ����ʲô��\n");
		return 1;
	}
	if(member_array(str, l_skills) == -1){
		tell_object(user,"���ּ����޷�����������������\n");
		return 1;
		}
	lvl = user->query_skill(str, 1);
	if(!lvl){
		tell_object(user,"�㲻�����ּ���\n");
		return 1;
	}
			
   user->start_busy(10);
   room = environment(user);
   tell_room(room, user->query("name") + "�������������"
      "����ʯ�����������������ʯ������\n", ({user}));
   tell_object(user, "�㿴�����������"
      "����ʯ�����������������ʯ������\n");
   call_out("lingwu_hook_completion", 4,user, str);
   return 1;
}

private nomask void lingwu_hook_completion(object user,string str)
{   
   int level;
      
   if(!user ||!objectp(present(this_object(), user)) || !str ) return;
   
   level = user->query_skill(str, 1);
   if(!level || level<150 || level%10!=0 || (user->query_learned()[str])<((level+1)*(level+1)-1) )
   	tell_object(user,"�������Ϊ���"+to_chinese(str)+"��Ϊ�����ң���ʲôҲû�����򵽡�\n");
   else{
   	message_vision("$N��ϸ����$n��Ȼ����ԭ�����������ʯ��$N��"+to_chinese(str)+"��Ϊ�ٳ߸�ͷ�ֽ�һ����\n",user,this_object());   	
   	user->improve_skill(str, 2);  // ��1���պ����� ֻ��1�ǽ������˵�
   }
   user->start_busy(-1);
   user->interrupt_me();
   destruct(this_object());

}
