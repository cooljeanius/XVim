//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Oct 10 2014 21:36:20).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

#import <AppKit/NSRulerView.h>

typedef NSRect(^GetParaBlock)(int);
@interface DVTTextSidebarView : NSRulerView
{
    double _sidebarWidth;	// 280 = 0x118
    double _foldbarWidth;	// 288 = 0x120
    NSColor *_sidebarBackgroundColor;	// 296 = 0x128
    NSColor *_sidebarEdgeColor;	// 304 = 0x130
    NSColor *_foldbarBackgroundColor;	// 312 = 0x138
    NSFont *_lineNumberFont;	// 320 = 0x140
    NSColor *_lineNumberTextColor;	// 328 = 0x148
    DVTTextAnnotation *_clickedAnnotation;	// 336 = 0x150
    DVTTextAnnotation *_currentlyRolledOverAnnotation;	// 344 = 0x158
    unsigned long long _origLineNumberOfAnnotationBeingDragged;	// 352 = 0x160
    NSTimer *_foldingHoverTimer;	// 360 = 0x168
    struct CGPoint _mouseLocationForContextualMenu;	// 368 = 0x170
    unsigned long long _hitLineNumberForContextualMenu;	// 384 = 0x180
    unsigned short _lineNumberDigitGlyphs[10];	// 392 = 0x188
    struct CGSize _lineNumberDigitGlyphAdvancements[10];	// 416 = 0x1a0
    NSTrackingArea *_trackingArea;	// 576 = 0x240
    unsigned long long _currentLineNumberReported;	// 584 = 0x248
    BOOL _showsSidebar;	// 592 = 0x250
    BOOL _showsFoldbar;	// 593 = 0x251
    BOOL _drawsLineNumbers;	// 594 = 0x252
    BOOL _clickedAnnotationHasTraveled;	// 595 = 0x253
}

- (void)_beginRolloverOnAnnotation:(id)arg1 event:(id)arg2;
- (id)_clickedAnnotation:(id)arg1;
- (unsigned long long)_drawFoldingRibbonForLine:(unsigned long long)arg1 foldbarRect:(struct CGRect)arg2 paraRect:(struct CGRect)arg3 lineNumberFontSize:(double)arg4 textView:(id)arg5;
- (void)_drawLineNumbersInSidebarRect:(CGRect)arg1 foldedIndexes:(NSUInteger *)arg2 count:(NSUInteger)arg3 linesToInvert:(id)arg4 linesToHighlight:(id)arg5 linesToReplace:(id)arg6 textView:(id)arg7 getParaRectBlock:(GetParaBlock)arg8;
- (void)_drawSidebarMarkersForAnnotations:(id)arg1 atIndexes:(id)arg2 textView:(id)arg3 getParaRectBlock:(GetParaBlock)arg4;
- (void)_endRolloverOnAnnotation:(id)arg1 event:(id)arg2;
- (void)_foldingHovered;
- (void)_fontAndColorSourceTextSettingsChanged:(id)arg1;
- (void)_reloadColors;
- (void)_scrollToMatchContentView;
- (void)_updateCurrentAnnotationRolloverStatusWithEvent:(id)arg1;
- (void)_updateCurrentMouseLineOver:(BOOL)arg1 withEvent:(id)arg2;
- (void)_updateRulerThickness;
- (BOOL)acceptsFirstMouse:(id)arg1;
- (BOOL)acceptsFirstResponder;
- (id)accessibilityAttributeNames;
- (id)accessibilityAttributeValue:(id)arg1;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (id)annotationAtSidebarPoint:(struct CGPoint)arg1;
- (void)dealloc;
- (void)didRemoveAnnotation:(id)arg1;
- (BOOL)displaysTooltips;
- (BOOL)dragAnnotationSidebarMarkerAtPoint:(struct CGPoint)arg1 draggableBounds:(struct CGRect)arg2 flipped:(BOOL)arg3 event:(id)arg4;
- (void)drawRect:(struct CGRect)arg1;
@property(nonatomic) BOOL drawsLineNumbers; // @synthesize drawsLineNumbers=_drawsLineNumbers;
- (struct CGRect)executionCountsRect;
@property(copy, nonatomic) NSColor *foldbarBackgroundColor; // @synthesize foldbarBackgroundColor=_foldbarBackgroundColor;
- (struct CGRect)foldbarRect;
@property double foldbarWidth; // @synthesize foldbarWidth=_foldbarWidth;
- (void)getParagraphRect:(struct CGRect *)arg1 firstLineRect:(struct CGRect *)arg2 forLineNumber:(unsigned long long)arg3;
- (id)initWithScrollView:(id)arg1 orientation:(unsigned long long)arg2;
@property(readonly) unsigned long long lastLineNumberControlClicked; // @synthesize lastLineNumberControlClicked=_hitLineNumberForContextualMenu;
- (id)lastMarkerControlClicked;
@property(readonly) struct CGPoint lastPointControlClicked; // @synthesize lastPointControlClicked=_mouseLocationForContextualMenu;
@property(retain, nonatomic) NSFont *lineNumberFont; // @synthesize lineNumberFont=_lineNumberFont;
- (unsigned long long)lineNumberForPoint:(struct CGPoint)arg1;
@property(copy, nonatomic) NSColor *lineNumberTextColor; // @synthesize lineNumberTextColor=_lineNumberTextColor;
- (struct CGRect)lineNumbersRect;
- (id)menuForEvent:(id)arg1;
- (void)mouseDown:(id)arg1;
- (void)mouseDownOnAnnotation:(id)arg1;
- (void)mouseDragged:(id)arg1;
- (void)mouseEntered:(id)arg1;
- (void)mouseExited:(id)arg1;
- (void)mouseMoved:(id)arg1;
- (void)mouseUp:(id)arg1;
- (BOOL)mouseUpOnAnnotationSidebarMarkerAtPoint:(struct CGPoint)arg1 bounds:(struct CGRect)arg2 event:(id)arg3;
- (void)prepareContentInRect:(struct CGRect)arg1;
- (void)recalculateSidebarWidthToFit;
- (void)scrollWheel:(id)arg1;
- (void)setLineNumberFont:(id)arg1 size:(double)arg2;
- (void)setOrientation:(unsigned long long)arg1;
@property(nonatomic) BOOL showsFoldbar; // @synthesize showsFoldbar=_showsFoldbar;
@property(nonatomic) BOOL showsSidebar; // @synthesize showsSidebar=_showsSidebar;
@property(copy, nonatomic) NSColor *sidebarBackgroundColor; // @synthesize sidebarBackgroundColor=_sidebarBackgroundColor;
@property(copy, nonatomic) NSColor *sidebarEdgeColor; // @synthesize sidebarEdgeColor=_sidebarEdgeColor;
@property(nonatomic) double sidebarWidth; // @synthesize sidebarWidth=_sidebarWidth;
@property(readonly) NSCursor *sidebarCursor;
- (struct CGRect)sidebarRect;
- (void)updateTrackingAreas;
- (void)viewDidMoveToWindow;
@end
