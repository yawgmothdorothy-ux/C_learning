from PIL import Image, ImageDraw, ImageFont
import math
from pathlib import Path

W, H = 2200, 1720
im = Image.new('RGB', (W, H), '#f6f8fc')
d = ImageDraw.Draw(im)
FONT = '/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc'
BOLD = '/usr/share/fonts/opentype/noto/NotoSansCJK-Bold.ttc'
def text(x,y,s,size=24,fill='#25344b',center=False,bold=False):
    f=ImageFont.truetype(BOLD if bold else FONT,size)
    d.text((x,y),s,font=f,fill=fill,anchor='mm' if center else 'lt')
def box(x,y,w,h,fill='#ffffff',outline='#cbd5e1'):
    d.rounded_rectangle((x,y,x+w,y+h),radius=13,fill=fill,outline=outline,width=2)
def arrow(x1,y1,x2,y2,color='#8194b0',width=3):
    d.line((x1,y1,x2,y2),fill=color,width=width)
    a=math.atan2(y2-y1,x2-x1)
    pts=[(x2,y2),(x2-13*math.cos(a-.45),y2-13*math.sin(a-.45)),(x2-13*math.cos(a+.45),y2-13*math.sin(a+.45))]
    d.polygon(pts,fill=color)
def array(cx,y,values,start,color):
    w=len(values)*55+20
    box(cx-w/2,y,w,86,color,'#8296ac')
    for q,v in enumerate(values):
        x=cx-w/2+10+q*55+27.5
        d.ellipse((x-21,y+9,x+21,y+51),fill='white',outline='#a1acbb',width=2)
        text(x,y+30,str(v),24,center=True,bold=True)
        text(x,y+67,str(start+q),18,center=True,fill='#607089')
def flow(y,lines,h=72,fill='#eef4ff'):
    box(1500,y,460,h,fill)
    for i,s in enumerate(lines): text(1730,y+22+i*28,s,22,center=True)

text(60,42,'归并排序：从 8 个元素到有序数组',42,bold=True)
text(60,103,'左侧看数据如何变化，右侧对照程序怎样执行。示例按从小到大排序。',26,fill='#607089')
box(35,165,1370,1490)
box(1430,165,735,1490)
text(65,191,'① 数据流程：拆分 → 单元素 → 合并',30,bold=True)
text(1460,191,'② 程序运行逻辑',30,bold=True)
rows=[
 [(730,[9,5,2,7,4,3,1,8],0)],
 [(440,[9,5,2,7],0),(1020,[4,3,1,8],4)],
 [(295,[9,5],0),(585,[2,7],2),(875,[4,3],4),(1165,[1,8],6)],
 [(222.5,[9],0),(367.5,[5],1),(512.5,[2],2),(657.5,[7],3),(802.5,[4],4),(947.5,[3],5),(1092.5,[1],6),(1237.5,[8],7)],
 [(295,[5,9],0),(585,[2,7],2),(875,[3,4],4),(1165,[1,8],6)],
 [(440,[2,5,7,9],0),(1020,[1,3,4,8],4)],
 [(730,[1,2,3,4,5,7,8,9],0)]
]
ys=[280,440,600,760,920,1080,1240]
for level in range(6):
    current,nxt=rows[level],rows[level+1]
    if len(nxt)>len(current):
        for idx,(x,_,_) in enumerate(current):
            for child in nxt[2*idx:2*idx+2]: arrow(x,ys[level]+86,child[0],ys[level+1]-5)
    else:
        for idx,(x,_,_) in enumerate(current): arrow(x,ys[level]+86,nxt[idx//2][0],ys[level+1]-5,'#639c7a')
labels=['原始数组','分成两半','继续对半分','递归停止','两两合并','合并成 4 个','最终结果']
for level,row in enumerate(rows):
    text(65,ys[level]+25,labels[level],22,bold=True)
    for cx,vals,start in row:
        array(cx,ys[level],vals,start,'#dcebff' if level<3 else ('#ffe8d5' if level==3 else '#ddf0df'))
    note={0:'下标 0..7；mid = 3',1:'区间 0..3 与 4..7',2:'只划分下标范围，不新建子数组',3:'left >= right：直接 return',4:'每次取左右两边较小的数',5:'两边都已排好，才能合并',6:'temp[left..right] 写回 arr'}[level]
    text(730,ys[level]+115,note,22,center=True,fill='#607089')
box(65,1430,1305,180,'#f0f5fb')
text(90,1450,'读图提示',25,bold=True)
text(90,1490,'• 圆圈是元素值，下方数字是当前数组位置；下标不会跟着元素移动。',23)
text(90,1530,'• 图按层展示便于理解；实际递归先完成左侧，再完成右侧，最后合并。',23)
text(90,1570,'• 合并阶段：i 指向左半部分，j 指向右半部分，k 指向 temp 的写入位置。',23)

text(1470,244,'main：输入、调用、输出',24,bold=True)
main=[(290,['读取 n，确认 n > 0']),(400,['申请 arr 和 temp','读取 n 个整数']),(530,['merge_sort(arr, temp, 0, n - 1)']),(640,['输出 arr，释放内存，结束'])]
for idx,(y,lines) in enumerate(main):
    h=88 if len(lines)>1 else 65
    flow(y,lines,h)
    if idx+1<len(main): arrow(1730,y+h,1730,main[idx+1][0]-8)
text(1470,740,'merge_sort：每一层的处理顺序',24,bold=True)
# 递归结束判断及其返回分支
cy=830
pts=[(1730,cy-42),(1930,cy),(1730,cy+42),(1530,cy)]
d.polygon(pts,fill='#fff0d9',outline='#c69542',width=2)
text(1730,cy,'left >= right ?',24,center=True,bold=True)
arrow(1930,cy,1995,cy)
text(1960,cy-25,'是',20,center=True)
box(2000,802,135,57,'#fff0d9'); text(2067,830,'return',23,center=True)
arrow(1730,872,1730,918)
text(1760,892,'否',20)
steps=[(930,['计算 mid，划分左右区间']),
       (1040,['递归左半部分 [left, mid]','等左侧调用返回，再继续']),
       (1170,['递归右半部分 [mid + 1, right]','等右侧调用返回，再继续']),
       (1300,['i = left，j = mid + 1，k = left','比较两边当前元素，小的写入 temp']),
       (1430,['复制尚未取完的一边','将 temp[left..right] 写回 arr']),
       (1560,['return：回到调用它的那一层'])]
for idx,(y,lines) in enumerate(steps):
    h=88 if len(lines)>1 else 65
    flow(y,lines,h,'#eaf5ec' if idx>=3 else '#eef4ff')
    if idx+1<len(steps): arrow(1730,y+h,1730,steps[idx+1][0]-8)
im.save(Path(__file__).parent/'merge-sort-guide.png')
