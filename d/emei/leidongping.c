// Room: /d/emei/leidongping.c 
// ������ �׶�ƺ


inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIR "�׶�ƺ" NOR);
        set("long", @LONG
�׶�ƺһ������·���պ��ˣ�·���Ǳ����������ɼ�֣�·���������
�ľ���Ͽ�ȡ����ﳤ���������֣����ɺڰ������Ͻ��������Ա���һ������
�ɴ������ǡ���ʮ���̡�����������µ�ϴ��ء�
LONG
        );
        set("outdoors", "����ɽ");
        set("exits", ([
                "northdown" : __DIR__"lingyunti",
                "southup" : __DIR__"basipan1",
        ]));
        
        set("lingwu", ([
                "skill" : "force",
                "low_limit" : 100,
                "up_limit" : 200,
                "lw_msg": BLU"$N������������������������أ������ں������Ǿ�������ר��˼����\n"+
                          "�����Լ���$s�ĵã�Ǳ������$b�������ѧ���⡣\n"NOR,
        ]));
        
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "southup" && (int)me->query_skill("dodge", 1) < 101 ) {
                me->improve_skill("dodge",(int)me->query("dex")/10);
                me->receive_damage("jingli",  (int)me->query("dex"));
                return 1; 
        }     
        return ::valid_leave(me, dir);

} 
