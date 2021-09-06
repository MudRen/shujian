#include <ansi.h>
#include <room.h>
inherit ROOM;
string look_left(object me);
string look_right(object me);
void create()
{
         set("short",HIY"����"NOR);
         set("long","���ɽ����һ����Ⱦ���ǳ��ɾ����������Զ������ƺ��п�ǳ���ı�ʯ��
   ӭ��ǽ���Ϲ�������ͼ��(tupu)�����Ϸ��ż������ţ���������˸��ط�����������\n"
);

          set("item_desc", ([
             "tupu" : "ǽ�Ϲ�������ͼ��(left)(right)���ƺ����������񽣵��书Ҫ�衣\n",
             "left": (: look_left :),
             "right": (: look_right :),
]));

        
set("exits", ([
               "south" : __DIR__"pyd",
        ]));
       
setup();
}
string look_left(object me)
{
       return YEL"\n����ͼ����һ�������濪�����������վã��ѳɽ���֮ɫ��ͼ�Ͽ�ͷд�ţ� \n"+
       "�������񽣡���һ��ָָ��Ϊ��������һ��ָ��ָ�������������������Σ��ɳ�������������ν������\n"+
       "����֮����̫���ξ��������İ����������ľ���̫��С����������θ��������������,�����񽣣���\n"+
       "�������������������������ν��������������Ų��ϻ��Ÿ��������ӵ�ͼ�Σ�����ע��Ѩλ���Ժ���\n"+
       "���߻������������߾������Ա�ע��һ��С�֡��������������š���\n" NOR;
}
string look_right(object me)
{
        return YEL"\n����ͼ����һ�������濪�����������վã��ѳɽ���֮ɫ��ͼ�϶����ݺύ���ֱ�ߡ�\n"+
        "ԲȦ�ͻ���,�������ߺ��ߣ��ݺύ��ͷ���׷�֮������ͼ�����������Ľ�����������ã�����׽����\n"+
        "�仯���临�ӡ�\n" NOR;
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
      
       if (neili<(j+1)*3000+1500&&!me->query("liumai-shenjian/shangyang"))
            return notify_fail("��߾�ȫ�����������ڵ�һ��ָ��������ͼ������Ѩ������ν�����ȴ�ް�㾢��������\n");

       
       if (lvl>30*(j+1))
            return notify_fail("���Ѿ��߾�ȫ��ȥ���ͼ���ϵľ�Ҫ�������ܸо��ھ��޷�����������\n");

       if (me->query("neili",1)<50)
            return notify_fail("��������첻���ˣ�\n");   
       if (me->query("jing",1)<50)
           return notify_fail("��ľ���첻���ˣ�\n");       
       me->receive_damage("jing",40+random(10));
       me->receive_damage("neili",40+random(10));
if (lvl>=30*(j+1)||me->query("liumai-shenjian/shangyang",1)){
       write("��������ת���磬����������ʳָ������������죬һ�����ν����ԡ�������Ѩ�м��������\n");
       if (!me->query("liumai-shenjian/shangyang"))
       me->add("liumai-shenjian/shangyang", 1);
       } else {
       write("������ͼ����ϰ�����������������ţ�������������еľ�Ҫ���ڡ�\n");
       if (!me->query("liumai-shenjian/shangyang"))
       me->improve_skill("liumai-shenjian", me->query("int"));
       }
       return 1;
  }else if (arg=="right") {
  	
       if (!me->query("liumai-shenjian/shangyang"))
            return notify_fail("���Ѿ��߾�ȫ��ȥ���ͼ���ϵĽ�������ϧ��һ·�����Ľ����㻹û�����ɣ�\n");
       if (me->query("neili",1)<60)
            return notify_fail("��������첻���ˣ�\n");   
       if (me->query("jing",1)<60)
            return notify_fail("��ľ���첻���ˣ�\n");
       me->receive_damage("jing",50+random(10));
       me->receive_damage("neili",50+random(10));
       write("�����Ž�����ϰ����������������������еľ�Ҫ���ڡ�\n");
       me->add_temp("shangyang", 1);
       if (me->query_temp("shangyang")>=10) {
       me->add("liumai-shenjian/shangyang", 1);
       me->set_temp("shangyang",0);
       write("������������Ĵָ�㴦����ͼ�ϵ���������������һ�顣\n");
       }
      return 1;
	}     
 }   
int valid_leave(object me, string dir)
{
       me->set_temp("shangyang", 0);
       return 1;        
}                    