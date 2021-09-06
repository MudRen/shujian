
//add �鿴quest skill by tangfeng 2005

#include <ansi.h>
inherit F_CLEAN_UP;
#define BUFFER_SIZE     1024
void searchstr(object me,string file,string str,int location,string buf);
void donext(string arg,object me,string file,string str,int location,string buf);
string sprint_list(object ob_list,string str);
int sort_user(object ob1, object ob2);
int clear_user(object ob);
int help(object me);

//�鿴skill
int chakan_skill(object me,int k);

mapping *quest_skill = ({
([      "location" : "quest/�����˲�/�书/pass",
        "name" : HIY"�貨΢��"NOR,
        "level" : 1,
		"logfile":"/log/quest/TLBB",
		"string":"�⿪�貨΢��",
]),
([      "location" : "oyf/hamagong3",
        "name" : HIY"��󡹦��"NOR,
        "level" : 1,
		"logfile":"/log/quest/hamagong",
		"string":"��󡹦",
]),
([      "location" : "quest/���Ǿ�/�书/shenzhao",
        "name" : HIB"���վ�"NOR,
        "level" : 2,
		"logfile":"/log/quest/LCHJ",
		"string":"ѧ�����վ�����",
]),
([      "location" : "quest/���Ǿ�/�书/sword",
        "name" : HIC"��ʬ����"NOR,
        "level" : 3,
		"logfile":"/log/quest/LCHJ",
		"string":"ѧ����ʬ����",
]),
([      "location" : "quest/ѩɽ�ɺ�/�书/hujiadaofa",
        "name" : HIW"���ҵ���"NOR,
        "level" : 2,
		"logfile":"/log/quest/FEIHU",
		"string":"�ҿ����ҵ���",
]),
([      "location" : "quest/ѩɽ�ɺ�/�书/miaojiajianfa",
        "name" : HIM"��ҽ���"NOR,
        "level" : 2,
		"logfile":"/log/quest/FEIHU",
		"string":"�ҿ���ҽ���",
]),
([      "location" : "quest/ѩɽ�ɺ�/�书/lengquanshengong",
        "name" : HIB"��Ȫ��"NOR,
        "level" : 2,
		"logfile":"/log/quest/FEIHU",
		"string":"�⿪��Ȫ��",
]),
([      "location" : "double_attack",
        "name" : HIR"˫�ֻ���"NOR,
        "level" : 1,
		"logfile":"/log/quest/jiebai",
		"string":"���ܲ�ͨ������˫�ֻ���",
]),
([      "location" : "quest/jiuyin2/pass",
        "name" : HIY"������ƪ"NOR,
        "level" : 2,
		"logfile":"/log/quest/jiuyin",
		"string":"�κ󣬴ӳ����紦�õ������澭�¾�",
]),
([      "location" : "quest/jiuyin1/pass",
        "name" : HIR"����ȫƪ"NOR,
        "level" : 1,
		"logfile":"/log/quest/jiuyin",
		"string":"�õ������澭�ϲ�",
]),
([      "location" : "mao18/pass",
        "name" : HIY"�廢���ŵ�"NOR,
        "level" : 3,
		"logfile":"/log/quest/wuhu",
		"string":"��éʮ�˴�ѧ���廢���ŵ�",
]),
([      "location" : "oyf/hamagong",
        "name" : HIR"��󡹦"NOR,
        "level" : 1,
		"logfile":"/log/quest/hamagong",
		"string":"��Ϊŷ��������",
]),
([      "location" : "quest/qianzhu/pass",
        "name" : HIR"ǧ������"NOR,
        "level" : 2,
		"logfile":"/log/quest/qianzhu",
		"string":"�󣬽⿪ǧ������",
]),
([      "location" : "jinshe/jianfa",
        "name" : HIY"���߽���"NOR,
        "level" : 2,
		"logfile":"",
		"string":"",
]),
([      "location" : "jinshe/zhangfa",
        "name" : HIY"�����Ʒ�"NOR,
        "level" : 3,
		"logfile":"",
		"string":"",
]),
([      "location" : "quest/pixie/pass",
        "name" : HIW"��а����"NOR,
        "level" : 2,
		"logfile":"/log/quest/pixie",
		"string":"�󣬻�á��������䡹",
]),
([      "location" : "xmsz",
        "name" : HIW"��ڤ����"NOR,
        "level" : 2,
		"logfile":"",
		"string":"",
]),
([      "location" : "quest/jindaoheijian/pass",
        "name" : HIW"�𵶺ڽ�"NOR,
        "level" : 2,
		"logfile":"/log/quest/jindaoheijian",
		"string":"�𵶺ڽ�",
]),
});

int main(object me, string arg)
{
	object ob;
	string str;

	str="\n";
	if (!wizardp(me))
		return notify_fail("ֻ����ʦ�ܲ쿴��\n");
	if (!arg)
		chakan_skill(me,0);
	else 
	{

			ob = present(arg, environment(me));
			if (!ob) ob = LOGIN_D->find_body(arg);
			if (!ob) ob = find_living(arg);
			if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭��״̬��\n");
			if(wizardp(ob)) return notify_fail("�㲻���Բ�ѯ��ʦ״̬\n");
			me->set_temp("quest/chakanobject",ob);
			chakan_skill(me,1);
	}
	return 1;
}

int chakan_skill(object me,int k)
{
	string str;
	object *ob_list,obj;
	int i,j,offset,x=1;
	string file;

    if(k==0)
	{
		str =  "\n      �� "+HIY"���߽����书��ѯ��"NOR+" ��\n";
		str += "�������ߩ��������������ө������������ߩө�������������\n";
		str += "��     ��     ��      ��   ��  ��     ��  �书����  ��\n";
		ob_list = filter_array(children(USER_OB), (: userp :));
		ob_list = filter_array(ob_list, (: !wizardp($1) :));
		ob_list = filter_array(ob_list, (: clear_user :));
		//ob_list = filter_array(ob_list, (: sort_user :));

		for(i=0; i <sizeof(ob_list); i++)
		{

			str += "�ĩ��������������������������ة��������ة�������������\n";
			for(j = sizeof(quest_skill)-1; j >= 0; j--)
			{
				if(ob_list[i]->query(quest_skill[j]["location"] ))
					str += sprint_list(ob_list[i],quest_skill[j]["name"]);
			}

		}
		if(!sizeof(ob_list)) 
		{
			str += "�ĩ��������������������������ة��������ة�������������\n";
			str+= "�ĩ���������������û�з����κν����书�Ĵ��ک���������\n";
		}
		str += "������������������������������������������������������\n";  
		tell_object(me,str);
	}
	else
	{
        obj=me->query_temp("quest/chakanobject");
		if(!obj) return 1;
		str =  "\n"+HIY+obj->query("name")+"�书��ѯ��"NOR+"\n";
		str += "��������������������������������������������������������������������������������\n";
		str += "���ɣ�"+obj->query("family/family_name");	
		str += "\n��������������������������������������������������������������������������������\n";
        x=0;
		for(i = sizeof(quest_skill)-1; i >= 0; i--)
		{
			if(obj->query(quest_skill[i]["location"]))
			{
				str +=""+quest_skill[i]["name"]+"\n";	
				x=1;
			}
			
		}
		if(x==0)
			str+= "û�з����κν����书�Ĵ��ک�����������������������������������������������������\n";
		str += "��������������������������������������������������������������������������������\n"NOR;
		tell_object(me,str);
		if(x==1)
		{
			for(i = sizeof(quest_skill)-1; i >= 0; i--)
			{
				if(obj->query(quest_skill[i]["location"] ))
				{
					if(quest_skill[i]["logfile"]=="")
						tell_object(me,"��ϧû��"+quest_skill[i]["name"]+"��Log��¼��\n");
					else
					{
						seteuid(geteuid(me));
						file = quest_skill[i]["logfile"];
						if( (offset=file_size(file))>=0 ) 
							searchstr(me,file,quest_skill[i]["string"],file_size(file),"");
					}
				}
			}
			str = NOR"��������������������������������������������������������������������������������\n"NOR;
			tell_object(me,str);
		}
		me->delete_temp("quest/chakanobject");
	}
    return 1;
}
int clear_user(object ob)
{
	int i;
	for( i = 0; i < (sizeof(quest_skill)-1); i++)
	{
        if(ob->query(quest_skill[i]["location"]))
			return 1;
	}
	return 0;	
}
int sort_user(object ob1, object ob2)
{
	string name1, name2;
	int l1 = wiz_level(ob1), l2 = wiz_level(ob2);

	if (l1 != l2) return l2 - l1;

	if (l1) {
		name1 = ob1->query("id");
		name2 = ob2->query("id");

		if (intp(name1)) name1 = "";
		if (intp(name2)) name2 = "";
		if (name1 > name2) return -1;
		if (name1 < name2) return 1;
		return 0;
	}

	reset_eval_cost();

	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");
	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;

	l1 = ob1->query("family/generation");
	l2 = ob2->query("family/generation");
	if (l1 != l2) return l1 - l2;

	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

string sprint_list(object ob_list,string str)
{
	string msg="";
	if(!str)
		str="������";
	msg = sprintf("��  %10s%-12s  %|10s  %|10s  " NOR "��\n",
			ob_list->query("name") ,
			"("+capitalize(ob_list->query("id"))+")",
			ob_list->query("family/family_name"),
			str);
	return msg;
}
void searchstr(object me,string file,string str,int location,string buf)
{
        string * s;
        int i,j,count;
		object obj;
		obj=me->query_temp("quest/chakanobject");
		if(!obj) return;

        count = 0;
        while (1) {
                i = location;
                location -= BUFFER_SIZE;
                if (location<0)
                        location=0;
                else
                        i = BUFFER_SIZE;
                s = explode(read_bytes(file,location,i)+buf,"\n");
                buf = s[0]+"\n";
                        
                if (location<=0) j=0; else j=1;
                for(i=sizeof(s)-1;i>=j;i--) {
                        if( strsrch(s[i],str,1)>=0 && strsrch(s[i],obj->query("name"),1)>=0) {
                                tell_object(me,s[i]+"\n");
                                count++;        
                        }
                }

                if (location<=0) 
                        return;

				if (count>20) {
                        count = 0;
                        tell_object(me,"== δ����� == (ENTER ������һҳ��q �뿪)");
                        input_to("donext",me,file,str,location,buf);
                        return;
                }
        }
        return;
} 
void donext(string arg,object me,string file,string str,int location,string buf)
{
        if( arg[0]!='q' )
                searchstr(me,file,str,location,buf);
        else
                tell_object(me,"��ѯ��ֹ��\n");
}

int help(object me)
{
	write("
������������������������������������������������������������
          ָ���ʽ : "+YEL"checkquestskill <......>"NOR"
������������������������������������������������������������"YEL"
       checkquestskill  ��ʦ�鿴�������quest skill���
checkquestskill <���>  ��ʦ�鿴ĳ���quest skill��¼\n"NOR"
������������������������������������������������������������\n"NOR);
return 1;
}
