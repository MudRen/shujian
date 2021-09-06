#include <ansi.h>
#include <room.h>
inherit ROOM;
string look_left(object me);
string look_right(object me);
void create()
{
         set("short",HIY"�г�"NOR);
         set("long","���ɽ����һ����Ⱦ���ǳ��ɾ����������Զ������ƺ��п�ǳ���ı�ʯ��
   ӭ��ǽ���Ϲ�������ͼ��(tupu)�����Ϸ��ż������ţ���������˸��ط�����������\n"
);

          set("item_desc", ([
             "tupu" : "ǽ�Ϲ�������ͼ��(left)(right)���ƺ����������񽣵��书Ҫ�衣\n",
             "left": (: look_left :),
             "right": (: look_right :),
]));

        
set("exits", ([
               "southwest" : __DIR__"pyd",
        ]));
       
setup();
}
string look_left(object me)
{
       return YEL"\n����ͼ����һ�������濪�����������վã��ѳɽ���֮ɫ��ͼ�Ͽ�ͷд�ţ� \n"+
       "�������񽣡���һ��ָָ��Ϊ��������һ��ָ��ָ�������������������Σ��ɳ�������������ν������\n"+
       "����֮����̫���ξ��������İ����������ľ���̫��С����������θ��������������,�����񽣣���\n"+
       "�������������������������ν��������������Ų��ϻ��Ÿ��������ӵ�ͼ�Σ�����ע��Ѩλ���Ժ���\n"+
       "���߻������������߾������Ա�ע��һ��С�֡��г彣�������š���\n" NOR;
}
string look_right(object me)
{
        return YEL"\n����ͼ����һ�������濪�����������վã��ѳɽ���֮ɫ��ͼ�϶����ݺύ���ֱ�ߡ�\n"+
        "ԲȦ�ͻ���,�������ߺ��ߣ��ݺύ��ͷ���׷�֮������ͼ�����г彣�Ľ������󿪴��أ�����������\n"+
        "һ��һ��֮�������ޱȡ�\n" NOR;
}
void init()
{
        add_action("do_study", "yanxi");
        add_action("do_study", "xuexi");
        add_action("do_study", "xiulian");    
}

int do_study(string arg)
{
       object me,weapon;
       string *skill;
       int j,lvl,neili;
       mapping skill_name;
       me=this_player();
       
       neili=me->query("max_neili");
       skill_name=me->query("liumai-shenjian");
       lvl=me->query_skill("liumai-shenjian",1);
       if (skill_name)
       skill=keys(skill_name);
       j=sizeof(skill);
       
       weapon = me->query_temp("weapon");
      
       if(me->is_busy()|| me->is_fighting()) return notify_fail("����æ���أ�\n");
       if (!arg) return 0;   
     
       if (weapon )
            return notify_fail("���������Ŷ�������ô����\n");   
    
       
       if(arg=="left" ) {
       	
       if (j>2) return notify_fail("���Ѿ��߾�ȫ��ȥ���ͼ���ϵľ�Ҫ�������ܸо����������ھ��޷���ת���磡\n");	
       if (lvl>30*(j+1)) me->set_skill("liumai-shenjian",30*(j+1));         
      
       if (neili<(j+1)*3000+1500&&!me->query("liumai-shenjian/zhongchong"))
            return notify_fail("��߾�ȫ�����������ڵ�һ��ָ��������ͼ���г�Ѩ������ν�����ȴ�ް�㾢��������\n");

       
       if (lvl>30*(j+1))
            return notify_fail("���Ѿ��߾�ȫ��ȥ���ͼ���ϵľ�Ҫ�������ܸо��ھ��޷�����������\n");

       if (me->query("neili",1)<50)
            return notify_fail("��������첻���ˣ�\n");   
       if (me->query("jing",1)<50)
            return notify_fail("��ľ���첻���ˣ�\n");         
       me->receive_damage("jing",40+random(10));
       me->receive_damage("neili",40+random(10));
if (lvl>=30*(j+1)||me->query("liumai-shenjian/zhongchong",1)){
       write("��������ת���磬������������ָӭ��һ�����������죬һ�����ν����ԡ��г塱Ѩ�м��������\n");
       if (!me->query("liumai-shenjian/zhongchong"))
       me->add("liumai-shenjian/zhongchong", 1);
       } else {
       write("������ͼ����ϰ�г彣�����������ţ�������������еľ�Ҫ���ڡ�\n");
       if (!me->query("liumai-shenjian/zhongchong"))
       me->improve_skill("liumai-shenjian", me->query("int"));
       }
       return 1;
  }else if (arg=="right") {
  	
       if (!me->query("liumai-shenjian/zhongchong"))
            return notify_fail("���Ѿ��߾�ȫ��ȥ���ͼ���ϵĽ�������ϧ��һ·�����Ľ����㻹û�����ɣ�\n");
       if (me->query("neili",1)<60)
            return notify_fail("��������첻���ˣ�\n");   
       if (me->query("jing",1)<60)
            return notify_fail("��ľ���첻���ˣ�\n");
       me->receive_damage("jing",50+random(10));
       me->receive_damage("neili",50+random(10));
       write("�����Ž�����ϰ�г彣����������������еľ�Ҫ���ڡ�\n");
       me->add_temp("zhongchong", 1);
       if (me->query_temp("zhongchong")>=10) {
       me->add("liumai-shenjian/zhongchong", 1);
       me->set_temp("zhongchong",0);
       write("��������������ָ�㴦����ͼ�ϵ��г彣��������һ�顣\n");
       }
      return 1;
	}     
 }   
int valid_leave(object me, string dir)
{
       me->set_temp("zhongchong", 0);
       return 1;        
}                    